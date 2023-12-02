#include "Food.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

Food::Food(GameMechs* thisgm){
    printf("the food is ifinfish \n");
    foodBucket = new objPosArrayList(5,5);
    foodposx = 0;
    foodposy = 0;
    food = '\0';
    objPos a ;
    objPos b ;
    int x = thisgm -> getBoardSizeX();
    int y = thisgm -> getBoardSizeY();
    int counter = 0; //sick gpt
    int counts=0;
    int z;

    while(counts<5){

       
        generatefood(x,y);
        a.setObjPos(foodposx,foodposy,food);
        for(z=0;z<5;z++)
        {
            foodBucket->getElement(b,z);
            if(b.isPosEqual(&a))
            {
                break;
            }
        }
        if(z==5)
        {
            foodBucket ->insertHead(a);
        }
        

        
       
        
    }
}

Food::~Food(){
    delete foodBucket;
}

void Food::generatefood(int x,int y)
{  

    foodposx =rand()%(x-2)+1;
    foodposy =rand()%(y-2)+1;
    food = (rand()%94) + 33;
    
    
    
}

void Food::getFoodbucket(objPosArrayList &Food_list){
    for(int i = 0; i < 5; i++){
        objPos a;
        foodBucket ->getElement(a,i);
        Food_list.insertHead(a);
    }
}