#ifndef SFMLIB_ASSIGNMENT_HPP
#define SFMLIB_ASSIGNMENT_HPP

#include <iostream>
#include <sstream>

namespace sfmlib {

    class assignment {
    public:
        assignment(int x, int y);
        [[nodiscard]] std::string to_string() const;
        friend std::ostream &operator<<(std::ostream &os, const assignment &assignment);
        [[nodiscard]] int get_x() const;
        [[nodiscard]] int get_y() const;
    private:
        int x;
        int y;
    };

}

#endif
