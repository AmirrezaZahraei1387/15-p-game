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
                 break;


             std::cin.clear();
             // ignore rest of line
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

             }
         incMoveNum1();
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
