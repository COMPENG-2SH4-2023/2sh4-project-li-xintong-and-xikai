#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

Food::Food(GameMechs* thisgm){
    foodBucket = new objPosArrayList();
    boundx = thisgm -> getBoardSizeX();
    boundy = thisgm -> getBoardSizeY();
}

Food::~Food(){
    delete foodBucket;
}

void Food::generatefood()
{   
    for(int i = 0; i < 5 ; i++){
        tempfood.x =rand()%(boundx-2)+1;
        tempfood.y =rand()%(boundy-2)+1;
        tempfood.symbol = (rand()%94) + 33;  
        foodBucket ->insertHead(tempfood); 
    }
}

void Food::getFoodbucket(objPosArrayList &Food_list){
    int a = foodBucket -> getSize();
    for(int i = 0; i < 5; i++){
        objPos a;
        foodBucket -> getElement(a,i);  
        Food_list.insertTail(a);
    }
}