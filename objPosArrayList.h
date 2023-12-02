#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int sizeList;
        int sizeArray;

    public:
        objPosArrayList();
        objPosArrayList(int sList,int sArray);//additional constructor
        objPosArrayList(const objPosArrayList &ArrayList); //deep copy constructor

        ~objPosArrayList();

        int getSize();
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);

        //return the head x
        int getHeadx();
        //return the head y
        int getHeady(); 

        int getTailx();

        int getTaily();

        bool detect_to_print(int x, int y);
};

#endif