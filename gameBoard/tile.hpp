//
// Created by KAVOSH on 8/12/2023.
//

#ifndef INC_15_PUZZLE_GAME_TILE_HPP
#define INC_15_PUZZLE_GAME_TILE_HPP
#include <iostream>

namespace GB {
    class Tile {
    public:

        explicit Tile(int value) : m_tileValue{value} {}

        [[nodiscard]] int tile() const { return m_tileValue; }

        friend inline std::ostream &operator<<(std::ostream &out, Tile &t);
        friend inline bool operator==(Tile& t, int i);

    private:
        int m_tileValue{};
    };



    inline std::ostream &operator<<(std::ostream &out, Tile &t) {
        out << t.m_tileValue;
        return out;
    }

    bool operator==(Tile &t, int i) {
        return t.m_tileValue == i;
    }
}
#endif //INC_15_PUZZLE_GAME_TILE_HPP
