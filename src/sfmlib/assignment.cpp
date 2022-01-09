#include "assignment.hpp"

namespace sfmlib {

    assignment::assignment(int x, int y) {
        this->x = x;
        this->y = y;
    }

    std::string assignment::to_string() const {
        std::stringstream buff;
        buff << "[assignment; x: " << x << ", y: " << y << "]";
        return buff.str();
    }

    std::ostream &operator<<(std::ostream &os, const assignment &assignment) {
        os << assignment.to_string();
        return os;
    }

    int assignment::get_x() const { return x; }
    int assignment::get_y() const { return y; }

}
