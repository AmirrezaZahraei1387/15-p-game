//
// Created by KAVOSH on 8/12/2023.
#include <utility>
#include <iterator>
#include <algorithm>
#include "../../info.hpp"
#include "board.hpp"
#include <random>




namespace GB {
    inline std::random_device rd{};
    inline std::mt19937 ran{rd()};

    std::ostream &operator<<(std::ostream &out, Board &board) {
        for (int i{0}; i < info::SIZE; ++i) {
            for (int j{0}; j < info::SIZE; ++j) {
                out << board.m_board[i][j] << "  ";
            }
            out << std::endl;
        }

        return out;
    }

    void Board::shuffle() {
        // shuffling the order of sub arrays
        std::shuffle(std::begin(m_board), std::end(m_board), ran);

        // shuffling the order of each subarray
        std::for_each(std::begin(m_board), std::end(m_board),
                      [](Board::subTile &arr) { std::shuffle(arr, arr + info::SIZE, ran); }
        );

        setIndex0S();
        prepare();
    }

    void Board::setIndex0S() {
        for (int i{0}; i < info::SIZE; ++i) {
            for (int j{0}; j < info::SIZE; ++j) {
                if (m_board[i][j] == 0) {
                    m_index0.x = i;
                    m_index0.y = j;
                    break;
                }
            }
        }
    }

    void Board::prepare() {
        std::swap(m_board[0][0], m_board[m_index0.x][m_index0.y]);
    }

}