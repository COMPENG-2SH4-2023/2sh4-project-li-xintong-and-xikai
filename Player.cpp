#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"

Player::Player(GameMechs* thisGMRef) //can been seen as the initial construct function //can been seen as the initial construct function
{
    myDir = STOP;
    // more actions to be included
    int a = 1;
    playerPosList = new objPosArrayList(a,ARRAY_MAX_CAP);
    objPos TEMP;
    TEMP.setObjPos(thisGMRef->getBoardSizeX(),thisGMRef->getBoardSizeY(),'*'); //init 赋给头的特性，中场开始
    playerPosList[0].insertHead(TEMP);
    mainGameMechsRef = thisGMRef;
    snake_length = 1;
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
        objPos* a = new objPos(); 
        playerPosList -> getHeadElement(*a);

        case UP:
            //playerPosList -> getElement(a,0);
            a -> y--;
            if(a -> y == 0){
                a-> y = (mainGameMechsRef -> getBoardSizeY()) - 1;
            }            
            playerPosList -> insertHead(*a);

            if((playerPosList -> getSize())!= snake_length){
                playerPosList -> removeTail();
            }
            break;
        case DOWN:
            //objPos b;
            //playerPosList -> getElement(b,0);
            a -> y++;
            if(a -> y == mainGameMechsRef->getBoardSizeY()){
                a -> y = 1;
            }
            playerPosList -> insertHead(*a);
            if((playerPosList -> getSize()) != snake_length){
                playerPosList -> removeTail();
            }
            break;
        case LEFT:
            //objPos c;
            //playerPosList -> getElement(c,0);
            a -> x--;
            playerPosList -> insertHead(*a);
            if(a -> x == 0){
                a -> x = (mainGameMechsRef -> getBoardSizeX()) - 1;
            }
            if((playerPosList -> getSize()) != snake_length){
                playerPosList -> removeTail();
            }
            break;
        case RIGHT:
            //objPos d;
            //playerPosList -> getElement(d,0);
            a -> x++;
            playerPosList -> insertHead(*a);
            if(a -> x == mainGameMechsRef->getBoardSizeX()){
                a -> x = 1;
            }
            if((playerPosList -> getSize()) != snake_length){
                playerPosList -> removeTail();
            }
            break;
    }
    // PPA3 Finite State Machine logic
}
void Player::addlength(){
    snake_length++;
}
void Player::dellength(){
    snake_length--;
}