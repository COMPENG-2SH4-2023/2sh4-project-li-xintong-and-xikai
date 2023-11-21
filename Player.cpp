#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    // more actions to be included
    // creat a fsm:
}

Player::~Player()
{   
    delete mainGameMechsRef;
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir() // CONNECTED WITH THE PLAY FUNCTION 
{
    if(MacUILib_hasChar()){
        char p_temp = MacUILib_getChar();    
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
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    switch(myDir != STOP){
        case UP:
         
    }
    // PPA3 Finite State Machine logic
}

