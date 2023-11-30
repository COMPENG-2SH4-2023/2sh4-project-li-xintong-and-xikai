#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{

    private:
        objPos foodPos; //self_generated
        char input; //stock
        bool exitFlag; //stock
        bool loseflag; //stock
        int score; //stock
        
        int boardSizeX;
        int boardSizeY;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        GameMechs(GameMechs* clip_board);
        ~GameMechs();
        
        bool getExitFlagStatus();
        void setExitTrue();

        bool getloseflagStatus();
        void setloseflagTrue();

        char getInput();
        void setInput(char this_input);

        void clearInput();

        int getBoardSizeX();
        void setBoardSizeX(int x);
        int getBoardSizeY();
        void setBoardSizeY(int y);

        void generatefood(objPos blockoff);
        void getFoodPos(objPos &blockoff); //pass by reference, eventhough the block itself do not have the characteristic of the pointers/.

};

#endif