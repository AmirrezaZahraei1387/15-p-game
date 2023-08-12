#include <iostream>
#include "gameBoard/board.hpp"


int main() {
    GB::Board board{};
    board.shuffleTiles();
    std::cout<<board;
    return 0;
}
