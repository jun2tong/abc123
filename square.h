#ifndef __SQUARE_H__
#define __SQUARE_H__
#include <iostream>

class Square{
    int colour;
    char type;
    char special;
    int r; 
    int c;
    textDisplay *td;
    bool locked;
public:
    Square(int r, int c, int colour, char t=0, char s=0);
    int getColour();
    char getType();
    char getSpecial();
    int getLocked();
    void setLocked();
    void setType(char t);
    int getR();
    int getC();
    void setDisplay(textDisplay &td);
    void setPos(int r, int c); 
    ~Square()=0;
};

#endif

