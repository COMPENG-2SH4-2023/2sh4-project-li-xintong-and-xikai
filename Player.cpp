#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"

Player::Player(GameMechs* thisGMRef) //can been seen as the initial construct function //can been seen as the initial construct function
{
    myDir = STOP;
    // more actions to be included
    int a=5;
    playerPosList = new objPosArrayList(a,ARRAY_MAX_CAP);
    
    playerPosList.aList->x = (thisGMRef->getBoardSizeX())/2 ;
    playerPosList.aList->y = (thisGMRef->getBoardSizeY())/2 ;
    playerPosList.aList->symbol = '*';
    mainGameMechsRef = thisGMRef;
}

Player::~Player()
{   
    //delete mainGameMechsRef; //only thing include private that might required to delete. //only thing include private that might required to delete.
    // delete any heap members here
    delete [] playerPosList;
}

void Player::getPlayerPos(objPosArrayList &returnPosList) //the snake head location, always print add very beginning first of the element. //the snake head location, always print add very beginning first of the element.
{
    int a=playerPosList->getSize();
    returnPosList=new objPosArrayList(a,ARRAY_MAX_CAP);
    for(int i=0; i<sizeList; i++)
    {
        returnPosList[i].aList->x = playerPosList[i].aList->x;
        returnPosList[i].aList->y = playerPosList[i].aList->y;
        returnPosList[i].aList->symbol = playerPosList[i].aList->symbol;
    }
    // return the reference to the playerPos array list
}

void Player::updatePlayerDir() // CONNECTED WITH THE PLAY FUNCTION FIXED 
{
    char input = mainGameMechsRef -> getInput();
    switch(input)
    {
        case 'W':
        case 'w':
            if(myDir != DOWN && myDir != UP)
                myDir = UP;
            break;
        case 'A':
        case 'a':
            if(myDir != RIGHT && myDir != LEFT)
                myDir = LEFT;
            break;
        case 'S':
        case 's':
            if(myDir != DOWN && myDir != UP)
                myDir = DOWN;
            break;
        case 'D':
        case 'd':
            if(myDir != RIGHT && myDir != LEFT)
                myDir = RIGHT;
            break;
    } 
    mainGameMechsRef -> clearInput();       
}

void Player::movePlayer() //fixed  //fixed 
{
    //myDir from input of analysitic 
    switch(myDir){
        case UP:
            playerPosList[0].aList->y--;
            if(playerPosList[0].aList->y == 0){
                playerPosList[0].aList->y = (mainGameMechsRef -> getBoardSizeY()) - 1;
            }
            break;
        case DOWN:
            playerPosList[0].aList->y++;
            if(playerPosList[0].aList->y == (mainGameMechsRef -> getBoardSizeY())){
                playerPosList[0].aList->y= 1;
            }
            break;
        case LEFT:
            playerPosList[0]->aList->x--;
            if(playerPosList[0]->aList->x == 0){
                playerPosList[0]->aList->x = (mainGameMechsRef -> getBoardSizeX()) - 1;
            }
            break;
        case RIGHT:
            playerPosList[0].aList->x++;
            if(playerPosList[0].aList->x == (mainGameMechsRef -> getBoardSizeX())){
                playerPosList[0].aList->x = 1;
            }
            break;
    }
    // PPA3 Finite State Machine logic
}

