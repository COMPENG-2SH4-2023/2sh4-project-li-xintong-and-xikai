#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
using namespace std;
#define DELAY_CONST 100000

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
GameMechs *thisgm; //initial the gamemech on the heap, since it required to operate in the whole game! 
Player *snake;
Food *foodbasket;
int main(void)
{
    Initialize();
    while(!(thisgm ->getExitFlagStatus()))  //both elect on operator
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}

void Initialize(void)
{   
    thisgm = new GameMechs(30,15); //creat a new heap using class initialization
    snake = new Player(thisgm);
    foodbasket = new Food(thisgm);
    foodbasket -> generatefood();
}

void GetInput(void)
{
    if(MacUILib_hasChar()){
        thisgm -> setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    if(thisgm -> getInput() == 'k'){
        thisgm -> setExitTrue();
    }
    if(thisgm -> getInput() == 'l'){
        snake ->increasingsnake();
    }
    snake ->updatePlayerDir();
    snake ->movePlayer();
    objPosArrayList foods;
    foodbasket ->getFoodbucket(foods);
    if(snake ->checkfoodconsumption(foods)){
        foodbasket -> generatefood();
    } 
    if(snake -> checkselfcollision()){
        thisgm -> setloseflagTrue();
        thisgm -> setExitTrue();
    }
}


void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPosArrayList printsnake;
    objPosArrayList printfoods;
    snake -> getPlayerPos(printsnake);
    foodbasket -> getFoodbucket(printfoods);
    for(int y = 0; y < 16; y++){
        for(int x = 0; x < 31; x++){
            if(x == 0 || x == 30){
                printf("#");
            }
            else if (y == 0 || y == 15){
                printf("#");
            }
            else if(printsnake.detect_to_print(x,y)){
                printf("%c",printsnake.detect_get_char());
            }
            else if(printfoods.detect_to_print(x,y)){
                printf("%c",printfoods.detect_get_char());
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Your current score is %d\n",thisgm -> getscore());
    printf("your current snake length is %d\n",printsnake.getSize());
    if(snake -> getaward() == 0){
        printf("you have not eat anything yet");
    }
    else if(snake -> getaward() == 1){
        printf("you get 2 points and increase body");
    }
    else if(snake -> getaward() == 2){
        printf("you get 1 points and increase body");
    }
    else if(snake -> getaward() == 3){
        printf("you get 4 score and reduce body");
    }
    else if(snake -> getaward() == 4){
        printf("you get 0 points but increase in body");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST*0.1); // 0.1s delay //DELAY_CONST
}

void CleanUp(void)
{   
    MacUILib_clearScreen();
    if(thisgm ->getloseflagStatus()){
        printf("ahahha loser!!!!!!!\n");
    }
    else{
        printf("why exit?\n");
    }
    printf("your final score is %d\n",thisgm ->getscore());
    delete thisgm;   
    delete snake;
    MacUILib_uninit();  
}
