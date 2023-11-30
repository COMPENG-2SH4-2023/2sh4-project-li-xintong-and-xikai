#include "GameMechs.h"
#define DEFAULT_SIZEX 30
#define DEFAULT_SIZEY 15

GameMechs::GameMechs()
{
    input = '\0';
    score = 0;
    exitFlag = false;
    loseflag = false;
    boardSizeX = DEFAULT_SIZEX;
    boardSizeY = DEFAULT_SIZEX;
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
GameMechs::GameMechs(GameMechs* clip_board){ //deep copy
    boardSizeX=clip_board->boardSizeX;
    boardSizeY=clip_board->boardSizeY;
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
    input = '\0';
}

void GameMechs::generatefood(objPos blockoff){ //blockoff contains the player positon
    do{
        foodPos.x = rand()%(boardSizeX) + 1 ;// from 1 - 29
        foodPos.y = rand()%(boardSizeY) + 1 ;// from 1 - 14
    }
    while(foodPos.x == blockoff.x && foodPos.y == blockoff.y);
}
void GameMechs::getFoodPos(objPos &returnPos){
    returnPos.x = foodPos.x; //strong pass by reference 
    returnPos.y = foodPos.y;
} //pass by reference, eventhough the block itself do not have the characteristic of the pointers/.
