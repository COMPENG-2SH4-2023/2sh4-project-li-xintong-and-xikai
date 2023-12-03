#include "Player.h"
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "objPos.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef) //can been seen as the initial construct function //can been seen as the initial construct function
{
    myDir = STOP;
    
    playerPosList = new objPosArrayList();
    
    objPos TEMP;
    TEMP.setObjPos((thisGMRef->getBoardSizeX())/2,(thisGMRef->getBoardSizeY())/2,'*'); //init 赋给头的特性，中场开始
    playerPosList -> insertHead(TEMP);

    mainGameMechsRef = thisGMRef;
}

Player::~Player()
{   
    //delete mainGameMechsRef; //only thing include private that might required to delete. //only thing include private that might required to delete.
    // delete any heap members here
    delete playerPosList;
}

void Player::getPlayerPos(objPosArrayList &returnPosList) //the snake head location, always print add very beginning first of the element. //the snake head location, always print add very beginning first of the element.
{
    int a = playerPosList -> getSize();
    for(int i=0; (i < playerPosList -> getSize()); i++)
    {   
        objPos a;
        playerPosList->getElement(a,i);
        returnPosList.insertTail(a);
    }
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
        case 'T':
        case 't':
            myDir = STOP;
            break;
    } 
    mainGameMechsRef -> clearInput();       
}

void Player::movePlayer() //fixed  //fixed 
{
    //myDir from input of analysitic 
    objPos a; //calculate the head position
    playerPosList -> getHeadElement(a);

    switch(myDir){
        
        case UP:
            //playerPosList -> getElement(a,0);
            a.y--;
            if(a.y == 0){
                a.y = (mainGameMechsRef -> getBoardSizeY()) - 1;
            }            
            playerPosList -> insertHead(a);
            playerPosList -> removeTail();
            break;
        case DOWN:
            //objPos b;
            //playerPosList -> getElement(b,0);
            a.y++;
            if(a.y == mainGameMechsRef->getBoardSizeY()){
                a.y = 1;
            }
            playerPosList -> insertHead(a);
            playerPosList -> removeTail();
            break;
        case LEFT:
            //objPos c;
            //playerPosList -> getElement(c,0);
            a.x--;
            
            if(a.x == 0){
                a.x = (mainGameMechsRef -> getBoardSizeX()) - 1;
            }
            playerPosList -> insertHead(a);
            playerPosList -> removeTail();
            break;
        case RIGHT:
            a.x++;
            
            if(a.x == mainGameMechsRef->getBoardSizeX()){
                a.x = 1;
            }
            playerPosList -> insertHead(a);
            playerPosList -> removeTail();
            break;
    }
    // PPA3 Finite State Machine logic
}

bool Player::checkfoodconsumption(objPosArrayList &food_list){
    objPos playerPOS;
    objPos TEMP_FOODPOS;
    playerPosList -> getHeadElement(playerPOS);
    for(int i = 0; i < 5 ; i++){
        food_list.getElement(TEMP_FOODPOS,i);
        if(TEMP_FOODPOS.isPosEqual(&playerPOS)&&TEMP_FOODPOS.symbol >=70 ){
            mainGameMechsRef -> scoreup(); 
            mainGameMechsRef -> scoreup(); 
            increasingsnake();
            printf("1");
            return true;
        }
        else if(TEMP_FOODPOS.isPosEqual(&playerPOS)&&TEMP_FOODPOS.symbol >=45 && TEMP_FOODPOS.symbol <70 ){
            mainGameMechsRef -> scoreup();
            increasingsnake();
            printf("2");
            return true;
        }
        else if(TEMP_FOODPOS.isPosEqual(&playerPOS)&&TEMP_FOODPOS.symbol == '!'){
            mainGameMechsRef -> scoreup();
            mainGameMechsRef -> scoreup();
            mainGameMechsRef -> scoreup();
            mainGameMechsRef -> scoreup();
            playerPosList ->removeTail();
            printf("3");
            return true;
        }
        else if(TEMP_FOODPOS.isPosEqual(&playerPOS)&&TEMP_FOODPOS.symbol == ')'){
            increasingsnake();
            printf("4");
            return true;
        }
    }
    printf("5");
    return false;
}

void Player::increasingsnake(){
    objPos head;
    playerPosList -> getHeadElement(head);
    playerPosList -> insertHead(head);
}

bool Player::checkselfcollision()
{
    objPos head;
    objPos body;
    for(int i = 2 ;(i < playerPosList -> getSize()); i++)
    {
        playerPosList -> getHeadElement(head);
        playerPosList -> getElement(body,i);
        if(body.x == head.x && body.y == head.y){
            return true;
        }
    }
    return false;
}

GameMechs* Player::getGM(GameMechs &GameMechs){
    return mainGameMechsRef;
}