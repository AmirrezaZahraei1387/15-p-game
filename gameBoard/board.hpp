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


    enum class CheckMode{
        SUCCESS,
        FAILURE
    };


    class PointIndex {
    public:



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

        [[nodiscard]] int& x(){return m_x;}
        [[nodiscard]] int& y(){return m_y;}

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

            setIndex0();
        }

        void prepare(){
            std::swap(m_board[m_index0.x()][m_index0.y()], m_board[0][0]);
            setIndex0();
        }

        void setIndex0(){
            for(int index_i{0}; index_i<SIZE; ++index_i) {
                for (int index_j{0}; index_j < SIZE; ++index_j) {
                    if(m_board[index_i][index_j] == 0) {

                        m_index0.x() = index_i;
                        m_index0.y() = index_j;

                        break;
                    }
                }
            }
        }

        CheckMode moveTile(PointIndex pointi)
        {
            if(pointi.x() == m_index0.x()){
                if(!(pointi.y()+1 == m_index0.y()|| pointi.y() -1 == m_index0.y()))
                    return CheckMode::FAILURE;

            }else if (pointi.y() == m_index0.y()) {
                if (!(pointi.x() + 1 == m_index0.x() || pointi.x() - 1 == m_index0.x()))
                    return CheckMode::FAILURE;
            }else
                return CheckMode::FAILURE;

            std::swap(m_board[pointi.x()][pointi.y()],
                      m_board[m_index0.x()][m_index0.y()]);
            return CheckMode::SUCCESS;
        }


        friend inline std::ostream& operator<<(std::ostream& out, Board& b);

    private:
        Tile m_board[SIZE][SIZE]{
                Tile{1}, Tile{2}, Tile{3}, Tile{4},
                Tile{5}, Tile{6}, Tile{7}, Tile{8},
                Tile{9}, Tile{10}, Tile{11}, Tile{12},
                Tile{13}, Tile{14}, Tile{15}, Tile{0},
        };
        PointIndex m_index0{SIZE -1, SIZE -1};
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
