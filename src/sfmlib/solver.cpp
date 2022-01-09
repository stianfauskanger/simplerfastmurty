#include "solver.hpp"

namespace sfmlib {

    result solver::solve(problem problem) {
        auto d = problem.get_data();
        double *cost_matrix = d.data();
        int nrows = problem.get_n();
        int ncolumns = problem.get_m();
        int nsolutions = problem.get_max_number_of_solutions();

        constexpr int nrow_priors = 1;
        constexpr int ncol_priors = 1;

        bool *row_priors = new bool[nrow_priors * nrows];
        for (int i = 0; i < nrow_priors * nrows; ++i) row_priors[i] = true;

        bool *col_priors = new bool[ncol_priors * ncolumns];
        for (int i = 0; i < ncol_priors * ncolumns; ++i) col_priors[i] = true;

        double row_prior_weights[nrow_priors] = {0};
        double col_prior_weights[ncol_priors] = {0};

        int *out_assocs = new int[nsolutions * (nrows + ncolumns) * 2];
        for (int i = 0; i < nsolutions * (nrows + ncolumns) * 2; ++i) out_assocs[i] = 0;

        auto *out_costs = new double[nsolutions];
        for (int i = 0; i < nsolutions; ++i) out_costs[i] = 0;

        WorkvarsforDA workvars = allocateWorkvarsforDA(nrows, ncolumns, nsolutions);

        bool error = da(cost_matrix,
                           nrow_priors, row_priors, row_prior_weights,
                           ncol_priors, col_priors, col_prior_weights,
                           nsolutions,
                           out_assocs,
                           out_costs,
                           &workvars);

        std::vector<solution> solutions;
        std::vector<double> costs;
        for (int solution_idx = 0; solution_idx < nsolutions; ++solution_idx) {
            double cost = out_costs[solution_idx];
            int out_assocs_idx = solution_idx * (nrows + ncolumns) * 2;
            int *association = &out_assocs[out_assocs_idx];
            std::vector<assignment> assignments;
            for (int i = 0; i < (nrows + ncolumns) * 2; i += 2) {
                int a = association[i];
                int b = association[i + 1];
                if (a < 0 || b < 0) continue;
                assignments.push_back(sfmlib::assignment(a, b));
            }
            sfmlib::solution solution(assignments, cost);
            solutions.push_back(solution);
            costs.push_back(cost);
        }

        sfmlib::result result(solutions, costs, error);

        deallocateWorkvarsforDA(workvars);
        delete[] out_costs;
        delete[] out_assocs;
        delete[] col_priors;
        delete[] row_priors;
        return result;
    }

    std::string solver::to_string() const {
        return "[solver]";
    }

    std::ostream &operator<<(std::ostream &os, const solver &solver) {
        os << solver.to_string();
        return os;
    }

}
