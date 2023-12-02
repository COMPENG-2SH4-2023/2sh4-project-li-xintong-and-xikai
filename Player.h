#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "objPos.h"
#include "GameMechs.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};
        Player(GameMechs* thisGMRef); 
        ~Player(); 

        void getPlayerPos(objPosArrayList &returnPosList); 
        void updatePlayerDir(); //FSM
        void movePlayer(objPosArrayList *food_list);//class
        

        bool checkfoodconsumption(objPosArrayList *food_list);
        bool checkselfcollision();

    private:
        objPosArrayList* playerPosList;   
        enum Dir myDir;     
        GameMechs* mainGameMechsRef; 
};

#endif