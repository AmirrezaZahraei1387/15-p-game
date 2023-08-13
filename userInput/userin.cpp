//
// Created by KAVOSH on 8/13/2023.
//
#include "userin.h"
#include <limits>

namespace UIN {

     GetIn::Input GetIn::checkInput(char input) const{
        switch (input){
            case 'w': return GetIn::Input::W_ST_UP;break;
            case 'a': return GetIn::Input::A_ST_LEFT;break;
            case 's': return GetIn::Input::S_ST_DOWN;break;
            case 'd': return GetIn::Input::D_ST_RIGHT;break;
            case 'q': return GetIn::Input::Q_QUIT_GAME;break;
            default: return GetIn::Input::ND;break;
        }
    }

    GetIn::Input GetIn::getInput() {

         char input{};
         Input result{};

         while(true){
             std::cout<<"please enter your command?(w, a, s, d, q):";
             std::cin>>input;
             result = checkInput(input);

             if(result != Input::ND)
                 return result;


             std::cin.clear();
             // ignore rest of line
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

             }
         incMoveNum1();
     }



    void GetIn::incMoveNum1() {
         m_moveNumber += 1;
    }

    int GetIn::getMoveNum() const{
        return m_moveNumber;
    }
}
