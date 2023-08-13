#include "board/boa/board.hpp"
#include "userInput/userin.h"
#include "info.hpp"


int main() {

    UIN::GetIn getIn{};
    info::ModeHap result;
    UIN::GetIn::Input input{};
    GB::Board board{};


    std::cout<<"welcome to the 15 puzzle game!!"<<std::endl;
    std::cout<<"let's begin!"<<std::endl;
    std::cout<<"here is what you should reach to."<<std::endl;
    std::cout<<board<<std::endl;
    std::cout<<"now let's shuffle it a little bit!"<<std::endl;
    board.shuffle();
    std::cout<<"and here is the board you should solve."<<std::endl;
    std::cout<<board<<std::endl;


    while(true) {
        input = getIn.getInput();

        if (input == UIN::GetIn::Input::Q_QUIT_GAME) {
            std::cout << "we miss you!" << std::endl;
            break;
        }

        result = board.moveTile(input);

        if (result == info::ModeHap::FAILURE) {
            std::cout << "bad move command. it can't be done!!!" << std::endl;
        } else {
            std::cout << "awsome"<<std::endl;
            getIn.incMoveNum1();
        }

        result = checkWin(board);
        if(result == info::ModeHap::SUCCESS){
            std::cout<<"you done it. you won"<<std::endl;
            break;
        }

        std::cout<<"the board is now something like this:"<<std::endl;
        std::cout<<board;

    }

    return 0;
}
