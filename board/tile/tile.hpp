//
// Created by KAVOSH on 8/12/2023.
//

#ifndef INC_15_PUZZLE_GAME_TILE_HPP
#define INC_15_PUZZLE_GAME_TILE_HPP
#include <iostream>


namespace GB{

    class Tile{
    public:
        explicit Tile(int value):m_value{value}{}
        friend inline std::ostream& operator<<(std::ostream& out, Tile& t);
    private:
        int m_value{};
    };

}
#endif //INC_15_PUZZLE_GAME_TILE_HPP
