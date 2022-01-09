#include "solution.hpp"

namespace sfmlib {

    solution::solution(std::vector<assignment> assignments, double cost) {
        this->assignments = assignments;
        this->cost = cost;
    }

    std::string solution::to_string() const {
        return "[solution;]";
    }

    std::string solution::to_full_string() const {
        std::stringstream buff;
        buff << "[solution;" << std::endl;
        buff << "\tcost: " << cost << std::endl;
        buff << "\tassignments.size: " << assignments.size() << std::endl;
        buff << "\tAssignments: " << std::endl;
        for (auto assignment : assignments) {
            buff << "\t - " << assignment.get_x() << " -> " << assignment.get_y() << std::endl;
        }
        buff << "]" << std::endl;
        return buff.str();
    }

    std::ostream &operator<<(std::ostream &os, const solution &solution) {
        os << solution.to_full_string();
        return os;
    }

    std::vector<assignment> const &solution::get_assignments() const { return assignments; }
    double solution::get_cost() const { return cost; }

}
