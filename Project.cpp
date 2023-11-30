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
GameMechs *a;
Player *thisplayer;

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
    a = new GameMechs(30,15); //creat a new heap using class initialization
    thisplayer = new Player(a); 
    
    
}

void GetInput(void)
{
   if(MacUILib_hasChar()){
        a -> setInput(MacUILib_getChar());
        thisplayer -> updatePlayerDir();
   }
}

void RunLogic(void)
{
    thisplayer -> movePlayer();
    

}

void DrawScreen(void)
{
    for(int y = 0; y < 16; y++){
        for(int x = 0; x < 31; x++){
            objPos comp;
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
    MacUILib_Delay(DELAY_CONST); // 0.1s delay //DELAY_CONST
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    MacUILib_uninit();
}
