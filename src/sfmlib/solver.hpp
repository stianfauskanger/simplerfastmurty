#ifndef SFMLIB_SOLVER_HPP
#define SFMLIB_SOLVER_HPP

#include <iostream>
#include "../fastmurty/da.hpp"
#include "result.hpp"
#include "problem.hpp"

namespace sfmlib {

    class solver {
    public:
        static sfmlib::result solve(sfmlib::problem problem);
        [[nodiscard]] std::string to_string() const;
        friend std::ostream &operator<<(std::ostream &os, const solver &solver);
    };

}

#endif
