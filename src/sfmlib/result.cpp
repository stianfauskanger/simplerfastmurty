#include "result.hpp"

namespace sfmlib {

    result::result(std::vector<solution> solutions, std::vector<double> costs, bool error) {
        this->solutions = solutions;
        this->costs = costs;
        this->error = error;
    }

    std::string result::to_string() const {
        return "[result;]";
    }

    std::string result::to_full_string() const {
        std::stringstream buff;
        buff << "[result;" << std::endl;
        buff << "\terror: " << error << std::endl;
        buff << "\tsolutions.size: " << solutions.size() << std::endl;
        int i = 1;
        for (auto solution : solutions) {
            buff << "\tSolution " << i++ << ":" << std::endl;
            buff << "\t\tcost: " << solution.get_cost() << std::endl;
            buff << "\t\tassignments.size: " << solution.get_assignments().size() << std::endl;
            buff << "\t\tAssignments: " << std::endl;
            for (auto assignment : solution.get_assignments()) {
                buff << "\t\t - " << assignment.get_x() << " -> " << assignment.get_y() << std::endl;
            }
        }
        buff << "]" << std::endl;
        return buff.str();
    }

    std::ostream &operator<<(std::ostream &os, const result &result) {
        os << result.to_full_string();
        return os;
    }

    std::vector<solution> const &result::get_solutions() const { return solutions; }
    std::vector<double> const &result::get_costs() const { return costs; }
    bool result::get_error() const { return error; }

}
