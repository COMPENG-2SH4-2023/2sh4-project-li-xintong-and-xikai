#include "GameMechs.h"
#define DEFAULT_SIZEX 30
#define DEFAULT_SIZEY 15

GameMechs::GameMechs()
{
    boardSizeX= DEFAULT_SIZEX;
    boardSizeY= DEFAULT_SIZEY;
}

GameMechs::GameMechs(int boardX, int boardY) //used as a setter
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
GameMechs::~GameMechs(){
    
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getloseflagStatus()
{
    return loseflag = true;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setloseflagTrue()
{
    loseflag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input; //deep copy
}

void GameMechs::clearInput()
{
    input ='\0';
}

void GameMechs::generatefood(objPos blockOff)
{
    do
    {
        foodPos.x=rand()%(boardSizeX-2)+1;
        foodPos.y=rand()%(boardSizeY-2)+1;
        foodPos.symbol='@';
    }
    while(foodPos.x==blockOff.x&&foodPos.y==blockOff.y);
    
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.x=foodPos.x;
    returnPos.y=foodPos.y;
    returnPos.symbol=foodPos.symbol;
}



