//
// Created by KAVOSH on 8/12/2023.
#include <utility>
#include <iterator>
#include <algorithm>
#include "../../info.hpp"
#include "board.hpp"
#include <random>
#include <cassert>



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
        m_index0.x = 0;
        m_index0.y = 0;
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

    info::ModeHap Board::moveTile(UIN::GetIn::Input input)
    {
        Point newIndex {};

        switch (input) {

            case UIN::GetIn::Input::W_ST_UP:

                newIndex.x = m_index0.x+1;
                newIndex.y = m_index0.y;

                return move(newIndex);

            case UIN::GetIn::Input::D_ST_RIGHT:

                newIndex.x = m_index0.x;
                newIndex.y = m_index0.y-1;

                return move(newIndex);

            case UIN::GetIn::Input::A_ST_LEFT:

                newIndex.x = m_index0.x;
                newIndex.y = m_index0.y+1;

                return move(newIndex);

            case UIN::GetIn::Input::S_ST_DOWN:

                newIndex.x = m_index0.x-1;
                newIndex.y = m_index0.y;

                return move(newIndex);

            // these two cases must never happen
            case UIN::GetIn::Input::Q_QUIT_GAME:
                assert("the quit game should be handled by the caller");

            case UIN::GetIn::Input::ND:
                assert ("the not defined should be handled by caller");
        }

    }

    info::ModeHap Board::move(Board::Point &p) {

        if(checkIndex(p) != info::ModeHap::FAILURE) {
            std::swap(m_board[p.x][p.y], m_board[m_index0.x][m_index0.y]);

            // setting index 0
            m_index0.x = p.x;
            m_index0.y = p.y;

            return info::ModeHap::SUCCESS;
        }
        return info::ModeHap::FAILURE;
    }

    info::ModeHap checkWin(Board &board) {

        int counter{-1};

        for(int i{info::SIZE - 1}; i >= 0; --i){
            for(int j{info::SIZE - 1}; j >= 0; --j){

                counter += 1;

                if(board.m_board[i][j] != counter)
                    return info::ModeHap::FAILURE;
            }
        }

        return info::ModeHap::SUCCESS;
    }

    info::ModeHap checkIndex(Board::Point &p){

        if (p.x >= info::SIZE || p.x < 0)
            return info::ModeHap::FAILURE;

        if(p.y >= info::SIZE || p.y< 0)
            return info::ModeHap::FAILURE;

        return info::ModeHap::SUCCESS;
    }

}