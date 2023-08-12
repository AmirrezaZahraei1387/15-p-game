//
// Created by KAVOSH on 8/12/2023.
//
#ifndef INC_15_PUZZLE_GAME_BOARD_HPP
#define INC_15_PUZZLE_GAME_BOARD_HPP

#include "../../info.hpp"
#include "../tile/tile.hpp"
#include <iostream>

namespace GB{

    class Board{
    public:
        friend std::ostream& operator<<(std::ostream& out, Board& board);

    private:
        Tile m_board[info::SIZE][info::SIZE]{
        Tile{1}, Tile{2}, Tile{3}, Tile{4},
        Tile{5}, Tile{6}, Tile{7}, Tile{8},
        Tile{9}, Tile{10}, Tile{11}, Tile{12},
        Tile{13}, Tile{14}, Tile{15}, Tile{0},
        };
    };
}
#endif //INC_15_PUZZLE_GAME_BOARD_HPP
