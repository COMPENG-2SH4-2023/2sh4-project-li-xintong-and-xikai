#ifndef FOOD_H
#define FOOD_H

#include<iostream>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"


class Food{
    private:
        objPosArrayList* foodBucket;
        int foodposx;
        int foodposy;
        char food;
    public:
        Food(GameMechs* thisgm);
        ~Food();
        void generatefood(int x, int y);//inside maingamemech!
        void getFoodPos(objPos &returnPos);
};
#endif
