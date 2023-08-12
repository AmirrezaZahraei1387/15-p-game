//
// Created by KAVOSH on 8/12/2023.
//

#ifndef INC_15_PUZZLE_GAME_POINTINDEX_H
#define INC_15_PUZZLE_GAME_POINTINDEX_H
#include "board.hpp" // for SIZE


namespace GB{



    class PointIndex {
    public:

        enum class CheckMode{
            SUCCESS,
            FAILURE
        };

        PointIndex(int x, int y):m_x{x}, m_y{y}{}

        [[nodiscard]] CheckMode check()const{
            auto checkV{
                [](int value)
            {return value>= SIZE || value < SIZE;}
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
    }
};

#endif //INC_15_PUZZLE_GAME_POINTINDEX_H
