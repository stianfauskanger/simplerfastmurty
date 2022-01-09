#include "problem.hpp"

namespace sfmlib {

    problem::problem(std::vector<double> data, int n, int m, int max_number_of_solutions) {
        this->data = data;
        this->n = n;
        this->m = m;
        this->max_number_of_solutions = max_number_of_solutions;
    }

    std::string problem::to_string() const {
        std::stringstream buff;
        buff << "[problem;" << " n: " << n << ", m: " << m
             << ", max_number_of_solution: " << max_number_of_solutions << ", data: ";
        for (auto x : data) {
            buff << x << ", ";
        }
        buff << "size: " << data.size() << "]";
        return buff.str();
    }

    std::ostream &operator<<(std::ostream &os, const problem &problem){
        os << problem.to_string();
        return os;
    }

    std::vector<double> const& problem::get_data() const { return data; }
    int problem::get_n() const { return n; }
    int problem::get_m() const { return m; }
    int problem::get_max_number_of_solutions() const { return max_number_of_solutions; }

}
