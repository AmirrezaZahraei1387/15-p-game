//
// Created by KAVOSH on 8/13/2023.
//
#ifndef INC_15_PUZZLE_GAME_USERIN_H
#define INC_15_PUZZLE_GAME_USERIN_H
#include <iostream>
#include "../info.hpp"

// different input must be handled
// w - slide tile up
//
// a - slide tile left
//
// s - slide tile down
//
// d - slide tile right
//
// q - quit game


namespace UIN{

    class GetIn{

    public:
        enum class Input {
            W_ST_UP,
            A_ST_LEFT,
            S_ST_DOWN,
            D_ST_RIGHT,
            Q_QUIT_GAME,
            ND,
        };
        [[nodiscard]] Input checkInput(char input) const;
        Input getInput();
        [[nodiscard]] int getMoveNum()const;

    private:
        void incMoveNum1();

        int m_moveNumber{0};
    };
}
#endif //INC_15_PUZZLE_GAME_USERIN_H
