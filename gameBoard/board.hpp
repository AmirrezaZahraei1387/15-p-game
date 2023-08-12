//
// Created by KAVOSH on 8/12/2023.
//
#ifndef INC_15_PUZZLE_GAME_BOARD_HPP
#define INC_15_PUZZLE_GAME_BOARD_HPP

#include <random>
#include <algorithm>
#include <iostream>
#include <utility>
#include "tile.hpp"

namespace GB {

    inline std::random_device rd{};
    inline std::mt19937 rn{rd()};

    inline constexpr int SIZE{4};


    class PointIndex {
    public:

        enum class CheckMode{
            SUCCESS,
            FAILURE
        };

        PointIndex(int x, int y):m_x{x}, m_y{y}{}

        [[nodiscard]] CheckMode check()const{

            auto checkV{

                    [](int value)->bool
                    {return value>= GB::SIZE || value < GB::SIZE;}
            };

            if(checkV(m_x) || checkV(m_y))
                return CheckMode::FAILURE;
            return CheckMode::SUCCESS;

        }

        [[nodiscard]] int x()const{return m_x;}
        [[nodiscard]] int y()const{return m_y;}

    private:
        int m_x{};
        int m_y{};
    };


    class Board {
    public:

        void shuffleTiles() {
            // shuffling all the rows inside the m_board
            std::shuffle(std::begin(m_board), std::end(m_board), rn);

            for(int index{0}; index< SIZE; ++index)
                // shuffling each member of rows
                std::shuffle(std::begin(m_board[index]), std::end(m_board[index]), rn);
        }

        void prepare(){
            // the prepare function will move the index zero the top left corner
            for(int index_i{0}; index_i<SIZE; ++index_i) {
                for (int index_j{0}; index_j < SIZE; ++index_j) {
                    if(m_board[index_i][index_j] == 0) {
                        std::swap(m_board[0][0], m_board[index_i][index_j]);
                        break;
                    }
                }
            }
        }

        void moveTile(){
            // by giving a special index of tile we will
            // use it to move a tile.

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
                out<<b.m_board[index_i][index_j]<<"  ";
            }
            out<<std::endl;
        }

        return out;
    }



}
#endif //INC_15_PUZZLE_GAME_BOARD_HPP
