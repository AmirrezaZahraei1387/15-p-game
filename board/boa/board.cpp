//
// Created by KAVOSH on 8/12/2023.
//
#include "../../info.hpp"
#include "board.hpp"


namespace GB {

    std::ostream &operator<<(std::ostream &out, Board &board) {
        for (int i{0}; i< info::SIZE; ++i) {
            for (int j{0}; j < info::SIZE; ++j){
                out<<board.m_board[i][j]<<"  ";
            }
            out<<std::endl;
        }

        return out;
    }

}