#ifndef SFMLIB_PROBLEM_HPP
#define SFMLIB_PROBLEM_HPP

#include <iostream>
#include <sstream>
#include <vector>

namespace sfmlib {

    class problem {
    public:
        problem(std::vector<double> data, int n, int m, int max_number_of_solutions);
        [[nodiscard]] std::string to_string() const;
        friend std::ostream &operator<<(std::ostream &os, const problem &problem);
        [[nodiscard]] std::vector<double> const& get_data() const;
        [[nodiscard]] int get_n() const;
        [[nodiscard]] int get_m() const;
        [[nodiscard]] int get_max_number_of_solutions() const;
    private:
        std::vector<double> data;
        int n;
        int m;
        int max_number_of_solutions;
    };

}

#endif
