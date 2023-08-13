#include "board/boa/board.hpp"


int main() {

    GB::Board b{};
    b.shuffle();
    std::cout<<b;

    return 0;
}
