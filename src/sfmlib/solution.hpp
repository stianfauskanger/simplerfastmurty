#ifndef SFMLIB_SOLUTION_HPP
#define SFMLIB_SOLUTION_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include "assignment.hpp"

namespace sfmlib {

    class solution {
    public:
        solution(std::vector<assignment> assignments, double cost);
        [[nodiscard]] std::string to_string() const;
        [[nodiscard]] std::string to_full_string() const;
        friend std::ostream &operator<<(std::ostream &os, const solution &solution);
        [[nodiscard]] std::vector<assignment> const& get_assignments() const;
        [[nodiscard]] double get_cost() const;
    private:
        std::vector<assignment> assignments;
        double cost;
    };

}

#endif
