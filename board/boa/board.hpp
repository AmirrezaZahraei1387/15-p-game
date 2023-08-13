//
// Created by KAVOSH on 8/12/2023.
//
#ifndef INC_15_PUZZLE_GAME_BOARD_HPP
#define INC_15_PUZZLE_GAME_BOARD_HPP

#include "../../info.hpp"
#include "../tile/tile.hpp"
#include <iostream>


namespace GB{

    class Board{
    public:

        using subTile = Tile[info::SIZE];

        struct Point{
            int x;
            int y;
        };

        void shuffle();
        friend std::ostream& operator<<(std::ostream& out, Board& board);

    private:

        // some functionalities of this class like shuffle will do something that
        // there will be no  way to find and set the index0 because of this the function
        // setIndex0 is created. it will do a complete search in the board and so it is expensive.
        // So in the cases that we can define the index0 we do without this function.
        void setIndex0S();

        // the game says that the spot must be in the top left corner
        // to prepare will move the spot (index 0) to this situation.
        void prepare();
        Point m_index0{info::SIZE -1, info::SIZE -1};


        subTile m_board[info::SIZE]{
        Tile{1}, Tile{2}, Tile{3}, Tile{4},
        Tile{5}, Tile{6}, Tile{7}, Tile{8},
        Tile{9}, Tile{10}, Tile{11}, Tile{12},
        Tile{13}, Tile{14}, Tile{15}, Tile{0},
        };
    };
}
#endif //INC_15_PUZZLE_GAME_BOARD_HPP
