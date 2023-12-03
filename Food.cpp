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
    bool pass = false;
    
    while(!pass){
        cout << "this syscle is calling" << endl;
        for(int i = 0; i < 5 ; i++){
            do{
            tempfood.x =rand()%(boundx-2)+1;
            tempfood.y =rand()%(boundy-2)+1;
            tempfood.symbol = (rand()%93) + 33; //do not have ' '
            }
            while(tempfood.x < 2 || tempfood.y < 2); 
            foodBucket -> insertHead(tempfood); 
        }
        for(int j = 0; j < 4 ; j++){
            objPos reference1;
            objPos reference2;
            foodBucket -> getElement(reference1, j);
            for(int k = j; k < 3 ;k++)
            {
                foodBucket -> getElement(reference2, k+1);
                if(reference1.x == reference2.x && reference1.y == reference2.y)
                {
                    pass = false;
                    for(int z = 0; z<5; z++)
                    {
                        foodBucket ->removeHead();
                    }
                }
                else{
                    pass = true;                    
                }
            }
        }
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