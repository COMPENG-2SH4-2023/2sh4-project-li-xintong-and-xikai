#ifndef FOOD_H
#define FOOD_H

#include<iostream>
#include "objPos.h"
#include "objPosArrayList.h"


class Food{
    private:
        objPosArrayList* foodBucket;
        int foodposx;
        int foodposy;
        char food;
    public:
        Food();
        ~Food();
        void generatefood(objPos blockOff);//inside maingamemech!
        void getFoodPos(objPos &returnPos);
};
#endif
