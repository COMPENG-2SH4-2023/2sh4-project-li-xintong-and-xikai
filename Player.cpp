#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"

Player::Player(GameMechs* thisGMRef) //can been seen as the initial construct function //can been seen as the initial construct function
{
    myDir = STOP;
    // more actions to be included
    int a=5;
    playerPosList = new objPosArrayList(a,ARRAY_MAX_CAP);
    objPos TEMP;
    TEMP.setObjPos(thisGMRef->getBoardSizeX(),thisGMRef->getBoardSizeY(),'*'); //init 赋给头的特性，中场开始
    playerPosList[0].insertHead(TEMP);
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
    //returnPosList=new objPosArrayList(a,ARRAY_MAX_CAP);
    for(int i=0; (i < playerPosList -> getSize()); i++)
    {   
        objPos a;
        playerPosList->getElement(a,i);
        returnPosList.insertTail(a);
        //returnPosList[i].aList->y = playerPosList[i].aList->y;
        //returnPosList[i].aList->symbol = playerPosList[i].aList->symbol;
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
            objPos a;
            getElement(&a,0);
            a.y=a.y--;
            playerPosList -> insertHead(a);
            if(playerPosList.aList->y == 0){
                playerPosList[0].aList->y = (mainGameMechsRef -> getBoardSizeY()) - 1;
            }
            if((playerPosList -> getSize())!= mainGameMechsRef -> getSize()){
                playerPosList -> removeTail();
            }
            break;
        case DOWN:
            objPos a;
            getElement(&a,0);
            a.y=a.y++;
            playerPosList -> insertHead(a);
            if(playerPosList.aList->y == mainGameMechsRef->getBoardSizeY()){
                playerPosList[0].aList->y = 1;
            }
            if((playerPosList -> getSize())!= mainGameMechsRef -> getSize()){
                playerPosList -> removeTail();
            }
            break;
        case LEFT:
            objPos a;
            getElement(&a,0);
            a.x=a.x--;
            playerPosList -> insertHead(a);
            if(playerPosList.aList->x == 0){
                playerPosList[0].aList->x = (mainGameMechsRef -> getBoardSizeX()) - 1;
            }
            if((playerPosList -> getSize())!= mainGameMechsRef -> getSize()){
                playerPosList -> removeTail();
            }
            break;
        case RIGHT:
            objPos a;
            getElement(&a,0);
            a.y=a.x++;
            playerPosList -> insertHead(a);
            if(playerPosList.aList->x == mainGameMechsRef->getBoardSizeX()){
                playerPosList[0].aList->x = 1;
            }
            if((playerPosList -> getSize())!= mainGameMechsRef -> getSize()){
                playerPosList -> removeTail();
            }
            break;
    }
    // PPA3 Finite State Machine logic
}

