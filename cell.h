#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <iostream>

class Square{
    int colour;
    char type;
    char special;
    int x;
    int y;
    textDisplay *td;
//  Square *neighbours[4];
    int numNeighbours;
    bool lock;
public:
    Square(int x, int y, int c, char t=0, char s=0);
    //void mutatesquare(int x, int y, int c, char t=0, char s=0);
    int getColour();
    char getType();
    char getSpecial();
    int getX();
    int getY();
    void setDisplay(textDisplay &td);
    void setPos(int x, int y);
    virtual bool checkMatch();
    virtual void notify(int x, int y, char d); //
    ~Square()=0;
};

#endif

