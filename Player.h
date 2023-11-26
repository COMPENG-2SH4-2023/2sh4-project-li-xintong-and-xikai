#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        void updatePlayerDir(); //FSM
        void movePlayer();

    private:
        objPos playerPos;   // with player position and character of player   
        enum Dir myDir;     //the direction dimensition 

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef; //包含着在程序运行中与其它的交互
        //主程序mainfunction 必须要与mainGameMechRef 交互
};

#endif