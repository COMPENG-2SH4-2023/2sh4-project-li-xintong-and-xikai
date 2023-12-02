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
objPosArrayList *print_list; //initial for print statement

int main(void)
{
    Initialize();
    while((thisgm -> getExitFlagStatus() == false) && (thisgm -> getloseflagStatus() == false))  //both elect on operator
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
    print_list = new objPosArrayList();
    foodBucket = new Food(thisgm);
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
    
    if(thisgm ->getInput() == 'f'){
        thisgm ->setExitTrue();
    }
    thisplayer -> movePlayer();
    
}

void DrawScreen(void)
{
    thisplayer -> getPlayerPos(*print_list);  
    for(int y = 0; y < 16; y++){
        for(int x = 0; x < 31; x++){
            if(x == 0 || x == 30){
                printf("#");
            }
            else if (y == 0 || y == 15){
                printf("#");
            }
            
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    MacUILib_clearScreen();    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay //DELAY_CONST
}


void CleanUp(void)
{   
    delete thisplayer;
    delete thisgm;  
    MacUILib_clearScreen();    
    MacUILib_uninit();
}
