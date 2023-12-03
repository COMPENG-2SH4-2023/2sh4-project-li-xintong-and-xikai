#ifndef FOOD_H
#define FOOD_H

#include<iostream>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"


class Food{
    private:
        objPosArrayList* foodBucket; //五个食物储存位置 notice: 由外部构建pointer同时改变内部的值将会改变外部嘛？
        
        objPos tempfood;
        int boundx;
        int boundy;

    public:
        Food(GameMechs* thisgm);//生成规避边境的食物，五个，并写回foodbucket里面！
        
        ~Food();
        void generatefood();//inside maingamemech! 
        void getFoodbucket(objPosArrayList &Food_list); //return food list 
};
#endif
