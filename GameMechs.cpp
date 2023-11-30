#include "GameMechs.h"
#define DEFAULT_SIZEX 30
#define DEFAULT_SIZEY 15

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseflag = false;
    boardSizeX = DEFAULT_SIZEX;
    boardSizeY = DEFAULT_SIZEX;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    if(boardX <= 0){
        boardSizeX = DEFAULT_SIZEX;
    }
    if(boardY <= 0){
        boardSizeY = DEFAULT_SIZEY;
    }
}
GameMechs::GameMechs(GameMechs* clip_board){ //deep copy
    boardSizeX = clip_board->boardSizeX;
    boardSizeY = clip_board->boardSizeY;
    if(clip_board->boardSizeX<=0){
        boardSizeX=DEFAULT_SIZEX;
    }
    if(clip_board->boardSizeY<=0){
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

void GameMechs::setBoardSizeX(int x)
{
    boardSizeX = x;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}
void GameMechs::setBoardSizeY(int y)
{
    boardSizeY = y;
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

