#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        Player(GameMechs* thisGMRef); 
        ~Player(); //used for snake !

        void getPlayerPos(objPosArrayList &returnPosList); // Upgrade this in iteration 3.
        void updatePlayerDir(); //FSM
        void movePlayer();//
        void addlength();
        void dellength();

    private:
        objPosArrayList* playerPosList;   // with player position and character of player   
        enum Dir myDir;     //the direction dimensition 

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef; //包含着在程序运行中与其它的交互

        int snake_length; //
        //主程序mainfunction 必须要与mainGameMechRef 交互
};

#endif