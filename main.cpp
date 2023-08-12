#include <iostream>
#include "gameBoard/board.hpp"


int main() {
    GB::Board board{};
    board.shuffleTiles();
    board.prepare();
    std::cout<<board;
    GB::PointIndex p{1, 0};
    board.moveTile(p);
    std::cout<<std::endl;
    std::cout<<board;
    return 0;
}
