//
// Created by KAVOSH on 8/13/2023.
//
#include "userin.h"
#include <limits>

namespace UIN {

     GetIn::Input GetIn::checkInput(char input) {
        switch (input){
            case 'w': return GetIn::Input::W_ST_UP;
            case 'a': return GetIn::Input::A_ST_LEFT;
            case 's': return GetIn::Input::S_ST_DOWN;
            case 'd': return GetIn::Input::D_ST_RIGHT;
            case 'q': return GetIn::Input::Q_QUIT_GAME;
            default: return GetIn::Input::ND;
        }
    }

    GetIn::Input GetIn::getInput() const {

         char input{};
         Input result{};
         while(true){
             std::cout<<"please enter your command?(w, a, s, d, q):";
             std::cin>>input;
             result = checkInput(input);

             if(result != Input::ND)
                 break;


             std::cin.clear();
             // ignore rest of line
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

             }
         std::cout<<std::endl;
         std::cout<<"you have enter "<<m_moveNumber<<" move numbers until now."<<std::endl;
         std::cout<<std::endl;
        return result;
     }



    void GetIn::incMoveNum1() {
         m_moveNumber += 1;
    }

    int GetIn::getMoveNum() const{
        return m_moveNumber;
    }
}
