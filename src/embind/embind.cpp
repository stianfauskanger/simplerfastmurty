#include "embind.hpp"

// embind std::vector<double>
EMSCRIPTEN_BINDINGS(my_double_vector) {
        emscripten::register_vector<double>("VectorOfDouble");
};

// embind std::vector<sfmlib::assignment>
EMSCRIPTEN_BINDINGS(my_assignment_vector) {
        emscripten::register_vector<sfmlib::assignment>("VectorOfAssignment");
};

// embind std::vector<sfmlib::solution>
EMSCRIPTEN_BINDINGS(my_solution_vector) {
        emscripten::register_vector<sfmlib::solution>("VectorOfSolution");
};

// embind sfmlib::assignment
EMSCRIPTEN_BINDINGS(my_assignment_class) {
        emscripten::class_<sfmlib::assignment>("AssignmentClass")
                .constructor<int, int>()
                .function("getX", &sfmlib::assignment::get_x)
                .function("getY", &sfmlib::assignment::get_y)
                .function("toString", &sfmlib::assignment::to_string)
        ;
};

// embind sfmlib::problem
EMSCRIPTEN_BINDINGS(my_problem_class) {
        emscripten::class_<sfmlib::problem>("ProblemClass")
                .constructor<std::vector<double>, int, int, int>()
                .function("getData", &sfmlib::problem::get_data)
                .function("getN", &sfmlib::problem::get_n)
                .function("getM", &sfmlib::problem::get_m)
                .function("getMaxNumberOfSolutions", &sfmlib::problem::get_max_number_of_solutions)
                .function("toString", &sfmlib::problem::to_string)
        ;
};

// embind sfmlib::result
EMSCRIPTEN_BINDINGS(my_result_class) {
        emscripten::class_<sfmlib::result>("ResultClass")
                .constructor<std::vector<sfmlib::solution>, std::vector<double>, bool>()
                .function("getSolutions", &sfmlib::result::get_solutions)
                .function("getCosts", &sfmlib::result::get_costs)
                .function("isError", &sfmlib::result::get_error)
                .function("toString", &sfmlib::result::to_string)
                .function("toFullString", &sfmlib::result::to_full_string)
        ;
};

// embind sfmlib::solution
EMSCRIPTEN_BINDINGS(my_solution_class) {
        emscripten::class_<sfmlib::solution>("SolutionClass")
                .constructor<std::vector<sfmlib::assignment>, double>()
                .function("getAssignments", &sfmlib::solution::get_assignments)
                .function("getCost", &sfmlib::solution::get_cost)
                .function("toString", &sfmlib::solution::to_string)
                .function("toFullString", &sfmlib::solution::to_full_string)
        ;
};

// embind sfmlib::solver
EMSCRIPTEN_BINDINGS(my_solver_class) {
        emscripten::class_<sfmlib::solver>("SolverClass")
                .function("toString", &sfmlib::solver::to_string)
                .class_function("solve", &sfmlib::solver::solve)
        ;
};
