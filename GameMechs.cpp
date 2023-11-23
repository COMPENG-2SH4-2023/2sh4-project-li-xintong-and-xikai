#include "GameMechs.h"
#define DEFAULT_SIZEX 30
#define DEFAULT_SIZEY 15

GameMechs::GameMechs()
{
    boardSizeX= DEFAULT_SIZEX;
    boardSizeY= DEFAULT_SIZEY;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    
    boardSizeX=boardX;
    boardSizeY=boardY;
    if(boardX<=0){
        boardSizeX=DEFAULT_SIZEX;
    }
    if(boardY<=0){
        boardSizeY=DEFAULT_SIZEY;
    }

    
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    exitFlag=1;
    return exitFlag
}

char GameMechs::getInput()
{

}

int GameMechs::getBoardSizeX()
{

}

int GameMechs::getBoardSizeY()
{
    
}


void GameMechs::setExitTrue()
{

}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}


