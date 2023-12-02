#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "GameMechs.h"

Food::Food(GameMechs* thisgm){
    foodBucket = new objPosArrayList(5,5);
    objPos *a = new objPos;
    objPos *b = new objPos;
    int x = thisgm ->getBoardSizeX();
    int y = thisgm ->getBoardSizeY();
    int counter;
    do{
        for (int i = 0; i < 5; i++){
            generatefood(x,y);
            a -> setObjPos(foodposx,foodposy,food);
            foodBucket -> insertHead(*a);
        }//after that will leave the last value
        for(int j = 0; j < 4; j++){
            foodBucket -> getElement(*b,j); //0-3
            if(a ->isPosEqual(b)){
                counter++;
            }
        }
    }
    while(counter == 4);
    delete a,b;
}

Food::~Food(){
    delete foodBucket;
}
void Food::generatefood(int x,int y)
{  

    do
    {
        foodposx =(rand()%(x)-2)+1;
        foodposy =(rand()%(y)-2)+1;
        food = (rand()%94) + 33;
    }
    while(foodposx >= x && foodposy >= y);
    
}

void Food::getFoodPos(objPos &returnPos)//note the ;!
{
    returnPos.x = foodposx;
    returnPos.y = foodposy;
    returnPos.symbol = food;
}
