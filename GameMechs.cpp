#include "GameMechs.h"
#define DEFAULT_SIZEX 30
#define DEFAULT_SIZEY 15

GameMechs::GameMechs()
{
<<<<<<< HEAD
    input = 0;
    score = 0;
    exitFlag = false;
    loseflag = false;
    boardSizeX = 30;
    boardSizeY = 15;
=======
    boardSizeX= DEFAULT_SIZEX;
    boardSizeY= DEFAULT_SIZEY;
>>>>>>> e2b75ad82785f091c6901fda4b39f0aca8ac94e8
}

GameMechs::GameMechs(int boardX, int boardY) //used as a setter
{
<<<<<<< HEAD
    input = 0;
    score = 0;
    exitFlag = false;
    loseflag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
=======
    
    boardSizeX=boardX;
    boardSizeY=boardY;
    if(boardX<=0){
        boardSizeX=DEFAULT_SIZEX;
    }
    if(boardY<=0){
        boardSizeY=DEFAULT_SIZEY;
    }

    
>>>>>>> e2b75ad82785f091c6901fda4b39f0aca8ac94e8
}

// do you need a destructor?
GameMechs::~GameMechs(){
    
}


bool GameMechs::getExitFlagStatus()
{
<<<<<<< HEAD
    return exitFlag;
}

bool GameMechs::getloseflagStatus()
{
    return loseflag = true;
=======
    exitFlag=1;
    return exitFlag
>>>>>>> e2b75ad82785f091c6901fda4b39f0aca8ac94e8
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
<<<<<<< HEAD
    return boardSizeY;
=======
    
>>>>>>> e2b75ad82785f091c6901fda4b39f0aca8ac94e8
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


