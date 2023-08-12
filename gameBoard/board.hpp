//
// Created by KAVOSH on 8/12/2023.
//
#ifndef INC_15_PUZZLE_GAME_BOARD_HPP
#define INC_15_PUZZLE_GAME_BOARD_HPP
#include "tile.hpp"
#include <random>
#include <algorithm>
#include <iostream>

namespace GB {

    inline std::random_device rd{};
    inline std::mt19937 rn{rd()};

    inline constexpr int SIZE{4};

    class Board {
    public:

        void shuffleTiles() {
            // shuffling all the tiles inside the m_board
            std::shuffle(std::begin(m_board), std::end(m_board), rn);
        }

        friend inline std::ostream& operator<<(std::ostream& out, Board& b);

    private:
        Tile m_board[SIZE][SIZE]{
                Tile{1}, Tile{2}, Tile{3}, Tile{4},
                Tile{5}, Tile{6}, Tile{7}, Tile{8},
                Tile{9}, Tile{10}, Tile{11}, Tile{12},
                Tile{13}, Tile{14}, Tile{15}, Tile{0},
        };
    };

    inline std::ostream &operator<<(std::ostream& out, Board& b) {

        for(int index_i{0}; index_i<SIZE; ++index_i) {
            for (int index_j{0}; index_j < SIZE; ++index_j){
                out<<b.m_board[index_i][index_j]<<'  ';
            }
            out<<std::endl;
        }

        return out;
    }

}
#endif //INC_15_PUZZLE_GAME_BOARD_HPP
