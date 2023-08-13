//
// Created by KAVOSH on 8/12/2023.
#include <algorithm>
#include "../../info.hpp"
#include "board.hpp"
#include <random>




namespace GB {
    inline std::random_device rd{};
    inline std::mt19937 ran{rd()};

    std::ostream &operator<<(std::ostream &out, Board &board) {
        for (int i{0}; i< info::SIZE; ++i) {
            for (int j{0}; j < info::SIZE; ++j){
                out<<board.m_board[i][j]<<"  ";
            }
            out<<std::endl;
        }

        return out;
    }

    void Board::shuffle() {
        std::shuffle(std::begin(m_board), std::end(m_board), ran);
    }
}