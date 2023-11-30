#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
///*
Player *thisplayer;
objPos a;
objPos comp;
GameMechs thisgm;
//creat is able to creat all through the main environment
//*/
int main(void)
{
    Initialize();
    while(exitFlag == false)  
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
    MacUILib_init();
    MacUILib_clearScreen();
    exitFlag = false;
    a.setObjPos(5,5,'*');
    thisplayer -> getPlayerPos(a);
    
}

void GetInput(void)
{
   if(MacUILib_hasChar()){
        char temp_input = MacUILib_getChar();
        thisgm.setInput(temp_input);
        thisplayer->updatePlayerDir();
   }
}

void RunLogic(void)
{
    
    

}

void DrawScreen(void)
{
    for(int y = 0; y < 16; y++){
        for(int x = 0; x < 31; x++){
            thisplayer -> getPlayerPos(comp);
            int a = comp.x;
            int b = comp.y;
            char c = comp.symbol;
            if(x == 0 || x == 30){
                printf("#");
            }
            else if (y == 0 || y == 15){
                printf("#");
            }
            else if (x == a && y == b){
                printf("%c",c);
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
    MacUILib_Delay(500000); // 0.1s delay //DELAY_CONST
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    MacUILib_uninit();
}
