#include "objPos.h"
using namespace std;
#include<iostream>
objPos::objPos() //when creat a objpos element, provide initial value to prevent garbage data
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
    //cout << "this module objpos is active" << endl;
}

objPos::objPos(objPos &o) //deep copy pass by reference, give the value to the new created element with giving data
//only pass for basic funtion
{
    x = o.x;
    y = o.y;
    symbol = o.symbol; //intake deep copy
    //cout << "this module objpos is active" << endl;
}


objPos::objPos(int xPos, int yPos, char sym) //written the new element by manually input with the data
{
    x = xPos;
    y = yPos;
    symbol = sym;
    //cout << "this module objpos is active" << endl;
}

void objPos::setObjPos(objPos o)   //if the function is not directly pass by value, do it with 2 step, set and get 
{
    x = o.x;
    y = o.y;
    symbol = o.symbol; //deep copy
    //cout << "this module objpos is active" << endl;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
    //cout << "this module objpos is active" << endl;
}

void objPos::getObjPos(objPos &returnPos) //giving back the value from the setobjpos,from the element giving by the outside,,?
{
    returnPos.setObjPos(x, y, symbol); //return with mult data
    //cout << "this module getobjpos is active" << endl;
}

char objPos::getSymbol() //get the charateristic from the element
{
    return symbol;
    //cout << "this module getobjpos is active" << endl;
}

bool objPos::isPosEqual(const objPos* refPos) //get whether it is equal from the objpos funcion,if we input some pointers from the inside
{
    return (refPos->x == x && refPos->y == y);
    //cout << "this module isps active" << endl;
}

char objPos::getSymbolIfPosEqual(const objPos* refPos)//return the sult if the pros Equal!
{
    //cout << "this module last active" << endl;
    if(isPosEqual(refPos))
        return getSymbol();
    else
        return 0;
}
