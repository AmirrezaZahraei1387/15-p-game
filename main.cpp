#include "board/boa/board.hpp"
#include "userInput/userin.h"

int main() {
    UIN::GetIn g{};
    GB::Board b{};

    b.shuffle();
    std::cout<<b<<std::endl;

    if(b.moveTile(g.getInput()) == info::ModeHap::FAILURE)
        std::cout<<"f";
    std::cout<<b;
    return 0;
}
