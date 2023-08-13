//
// Created by KAVOSH on 8/12/2023.
//

#include "tile.hpp"
#include <iostream>

namespace GB {
    Tile& Tile::operator=(const Tile &t) {

        if (&t != this)
            m_value = t.m_value;

        return *this;
    }


    std::ostream &operator<<(std::ostream &out, Tile &t) {
        out << t.m_value;
        return out;
    }

    bool operator==(Tile &t, int n) {
        return t.m_value == n;
    }

    bool operator!=(Tile &t, int n) {
        return t.m_value != n;
    }
}