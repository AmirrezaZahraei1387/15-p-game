//
// Created by KAVOSH on 8/12/2023.
//

#ifndef INC_15_PUZZLE_GAME_TILE_HPP
#define INC_15_PUZZLE_GAME_TILE_HPP
#include <iostream>


class Tile{
public:

    Tile() = default;
    [[nodiscard]] int tile()const{return m_tileValue;}
    friend inline std::ostream& operator<<(std::ostream& out, Tile& t);
    
private:
    int m_tileValue{};
};

inline std::ostream &operator<<(std::ostream &out, Tile &t) {
    out<<t.m_tileValue;
    return out;
}

#endif //INC_15_PUZZLE_GAME_TILE_HPP
