#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
GameMechs *thisgm; //initial the gamemech
Player *thisplayer; //initial the player, the operation will cross the game
Food *foodBucket; //initial the food
objPosArrayList *player_list, *food_list; //initial for print statement

int main(void)
{
    Initialize();
    while(thisgm -> getExitFlagStatus())  //both elect on operator
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
    thisplayer = new Player(thisgm);
    player_list = new objPosArrayList();


    foodBucket = new Food(thisgm);
    food_list = new objPosArrayList();
    foodBucket -> getFoodbucket(*food_list);

}

void GetInput(void)
{
   if(MacUILib_hasChar()){
        thisgm -> setInput(MacUILib_getChar());
        thisplayer -> updatePlayerDir();
   }
}

void RunLogic(void)
{
    foodBucket = new Food(thisgm);
    food_list = new objPosArrayList();
    foodBucket -> getFoodbucket(*food_list);
    thisplayer ->getPlayerPos(*player_list);
    MacUILib_clearScreen();
    if(thisgm ->getInput() == 'f'){
        thisgm ->setExitTrue();
    }
    thisplayer -> movePlayer(food_list);
}

void DrawScreen(void)
{
    for(int i = 0 ; i < 5 ; i ++){
        objPos a;
        food_list ->getElement(a,i);
        printf("%d,%d,%c\n",a.x,a.y,a.symbol);
    }
    for(int y = 0; y < 16; y++){
        for(int x = 0; x < 31; x++){
            if(x == 0 || x == 30){
                printf("#");
            }
            else if (y == 0 || y == 15){
                printf("#");
            }
            else if(player_list -> detect_to_print(x,y)){
                printf("*");
            }
            else if(food_list -> detect_to_print(x,y)){
                printf("@");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST*0.01); // 0.1s delay //DELAY_CONST
}


void CleanUp(void)
{   
    MacUILib_clearScreen();
    delete thisplayer;
    delete thisgm;     
    MacUILib_uninit();
    if(thisgm ->getloseflagStatus()){
        MacUILib_printf("ahahha loser!!!!!!!");
    }
    MacUILib_printf("your final score is %d",thisgm ->getscore());
}
