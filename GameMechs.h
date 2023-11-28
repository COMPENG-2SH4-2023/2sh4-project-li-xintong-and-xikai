#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        objPos foodPos;
        char input;
        bool exitFlag;
        bool loseflag;
        int score;
        
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
        bool getExitFlagStatus();
        void setExitTrue();

        bool getloseflagStatus();
        void setloseflagTrue();

        char getInput();
        void setInput(char this_input);

        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        void generatefood(objPos blockOff);
        void getFoodPos(objPos &returnPos);

    
};

#endif