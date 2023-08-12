//
// Created by KAVOSH on 8/12/2023.
//
#ifndef INC_15_PUZZLE_GAME_BOARD_HPP
#define INC_15_PUZZLE_GAME_BOARD_HPP

#include "tile.hpp"
#include <vector>

class Board{
public:
    explicit Board(int size=4){

    }

private:
    std::vector<Tile>* board;
};

#endif //INC_15_PUZZLE_GAME_BOARD_HPP
