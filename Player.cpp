#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef) //can been seen as the initial construct function
{
    playerPos.x = thisGMRef -> getBoardSizeX();
    playerPos.y = thisGMRef -> getBoardSizeY();
    playerPos.symbol = '*';
    myDir = STOP;
    // more actions to be included
    mainGameMechsRef = thisGMRef;
}

Player::~Player()
{   
    delete mainGameMechsRef; //only thing include private that might required to delete.
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos) //the snake head location, always print add very beginning first of the element.
{
    returnPos.x = playerPos.x; //intergrate with both ability
    returnPos.y = playerPos.y; //deep copy direct pass the value to the 
    // return the reference to the playerPos array list
}

void Player::updatePlayerDir() // CONNECTED WITH THE PLAY FUNCTION FIXED 
{
    if(mainGameMechsRef->getInput() != NULL){//check the mainGamemechref weather have neo content
        char p_temp = mainGameMechsRef -> getInput(); // pass the reference     
        if(p_temp == (('w') || ('W'))&&(myDir != DOWN)){
            myDir = UP;
        }
        else if(p_temp = (('s') || ('S'))&&(myDir != UP)){
            myDir = DOWN;
        }
        else if(p_temp = (('a') || ('A'))&&(myDir != RIGHT)){
            myDir = LEFT;
        }
        else if(p_temp = (('d') || ('D'))&&(myDir != LEFT)){
            myDir = RIGHT;
        }
        else if(p_temp = (('t') || ('T'))){
            myDir = STOP;
        }
    }
    //myDir == NULL; // CLEAR 
    // PPA3 input processing logic        
}

void Player::movePlayer() //fixed 
{
    //myDir from input of analysitic 

    switch(myDir != STOP){
        case UP:
            playerPos.y--;
            if(playerPos.y == 0){
                playerPos.y = 14;
            }
            break;
        case DOWN:
            playerPos.y++;
            if(playerPos.y == 15){
                playerPos.y = 1;
            }
            break;
        case LEFT:
            playerPos.x--;
            if(playerPos.x == 0){
                playerPos.x = 29;
            }
            break;
        case RIGHT:
            playerPos.x++;
            if(playerPos.x == 30){
                playerPos.x = 1;
            }
            break;
    }
    // PPA3 Finite State Machine logic
}

