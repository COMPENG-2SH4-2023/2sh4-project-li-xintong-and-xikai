#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"

Food::Food(){


}

Food::~Food(){
    delete foodBucket;
}
void Food::generatefood(objPos blockoff)
{  
    
    do
    {
        int foodPosx =(rand()%(blockoff.x)-2)+1;
        int foodPosy =(rand()%(blockoff.y)-2)+1;
        int foodPossymbol='*';
    }
    while(foodPosx == blockoff.x && foodPosy==blockoff.y);
    
}

void Food::getFoodPos(objPos &returnPos);
{
    returnPos.x=foodPos.x;
    returnPos.y=foodPos.y;
    returnPos.symbol=foodPos.symbol;
}
