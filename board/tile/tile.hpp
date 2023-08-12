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
        Tile& operator= (Tile& t);

        friend bool operator== (Tile& t, int n);
        friend std::ostream& operator<<(std::ostream& out, Tile& t);

    private:
        int m_value{};
    };

}
#endif //INC_15_PUZZLE_GAME_TILE_HPP
