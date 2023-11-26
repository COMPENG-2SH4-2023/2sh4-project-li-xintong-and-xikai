#include "objPos.h"
using namespace std;
#include<iostream>
objPos::objPos()
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
    cout << "this module objpos is active" << endl;
}

objPos::objPos(objPos &o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol; //intake deep copy
    cout << "this module objpos is active" << endl;
}


objPos::objPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
    cout << "this module objpos is active" << endl;
}

void objPos::setObjPos(objPos o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol; //deep copy
    cout << "this module objpos is active" << endl;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
    cout << "this module objpos is active" << endl;
}

void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol); //return with mult data
    cout << "this module getobjpos is active" << endl;
}

char objPos::getSymbol()
{
    return symbol;
    cout << "this module getobjpos is active" << endl;
}

bool objPos::isPosEqual(const objPos* refPos)
{
    return (refPos->x == x && refPos->y == y);
    cout << "this module isps active" << endl;
}

char objPos::getSymbolIfPosEqual(const objPos* refPos)
{
    cout << "this module last active" << endl;
    if(isPosEqual(refPos))
        return getSymbol();
    else
        return 0;
}
