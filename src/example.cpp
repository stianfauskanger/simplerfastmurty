#include <iostream>
#include <vector>
#include "sfmlib/solver.hpp"
#include "sfmlib/problem.hpp"
#include "sfmlib/result.hpp"

int main()
{
    std::vector<double> list = {
            // if assigned wanted task:   cost = -1001
            // if assigned unwanted task: cost =  1000
            // if not assigned:           cost =  0 (by "definition" of fastmurty implementation)
            -1001,  1000, 1000, // Person 0 wants task 0
             1000, -1001, 1000, // Person 1 wants task 1
            -1001, -1001, 1000  // Person 2 wants task 0 or 1
    };
    sfmlib::problem problem(list, 3, 3, 10);
    std::cout << problem << std::endl;

    sfmlib::result result = sfmlib::solver::solve(problem);

    std::cout << result << std::endl;
//    --
//    for (const auto& solution : result.get_solutions()) {
//        std::cout << solution << std::endl;
//    }
//    --
//    for (const auto& assignment : result.get_solutions().at(0).get_assignments()) {
//        std::cout << assignment << std::endl;
//    }

    return 0;
}
