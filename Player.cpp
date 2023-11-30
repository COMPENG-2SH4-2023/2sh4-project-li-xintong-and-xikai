#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef) //can been seen as the initial construct function //can been seen as the initial construct function
{
    myDir = STOP;
    // more actions to be included
    playerPos.x = (thisGMRef->getBoardSizeX())/2 ;
    playerPos.y = (thisGMRef->getBoardSizeY())/2 ;
    playerPos.symbol = '*';
    mainGameMechsRef = thisGMRef;
}

Player::~Player()
{   
    //delete mainGameMechsRef; //only thing include private that might required to delete. //only thing include private that might required to delete.
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos) //the snake head location, always print add very beginning first of the element. //the snake head location, always print add very beginning first of the element.
{
    returnPos.x = playerPos.x;
    returnPos.y = playerPos.y;
    returnPos.symbol = playerPos.symbol;
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
            playerPos.y--;
            if(playerPos.y == 0){
                playerPos.y = (mainGameMechsRef -> getBoardSizeY()) - 1;
            }
            break;
        case DOWN:
            playerPos.y++;
            if(playerPos.y == (mainGameMechsRef -> getBoardSizeY())){
                playerPos.y = 1;
            }
            break;
        case LEFT:
            playerPos.x--;
            if(playerPos.x == 0){
                playerPos.x = (mainGameMechsRef -> getBoardSizeX()) - 1;
            }
            break;
        case RIGHT:
            playerPos.x++;
            if(playerPos.x == (mainGameMechsRef -> getBoardSizeX())){
                playerPos.x = 1;
            }
            break;
    }
    // PPA3 Finite State Machine logic
}

