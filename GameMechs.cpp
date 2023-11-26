#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseflag = false;
    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY) //used as a setter
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseflag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
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
    input = NULL;
}


