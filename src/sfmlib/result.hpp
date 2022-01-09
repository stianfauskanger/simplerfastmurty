#ifndef SFMLIB_RESULT_HPP
#define SFMLIB_RESULT_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include "solution.hpp"

namespace sfmlib {

    class result {
    public:
        result(std::vector<solution> solutions, std::vector<double> costs, bool error);
        [[nodiscard]] std::string to_string() const;
        [[nodiscard]] std::string to_full_string() const;
        friend std::ostream &operator<<(std::ostream &os, const result &result);
        [[nodiscard]] std::vector<solution> const& get_solutions() const;
        [[nodiscard]] std::vector<double> const& get_costs() const;
        [[nodiscard]] bool get_error() const;
    private:
        std::vector<solution> solutions;
        std::vector<double> costs;
        bool error;
    };

}

#endif
