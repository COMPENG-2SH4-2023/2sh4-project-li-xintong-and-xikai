#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int sizeList; //snake length mapping
        int sizeArray; //acutal snake body length

    public:
        objPosArrayList();
        objPosArrayList(int sList,int sArray);//additional constructor
        objPosArrayList(const objPosArrayList &ArrayList); //deep copy constructor

        ~objPosArrayList();

        int getSize();
        
        //snake operation interact with snake 
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        //snake feature, using for snake 
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);

        //return the head x
        int getHeadx();
        //return the head y
        int getHeady(); 

        int getTailx();

        int getTaily();
        
        //food and snake print 
        bool detect_to_print(int x, int y);
};

#endif