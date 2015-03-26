#ifndef __board_h__
#define __board_h__
#include "square.h"
#include <iostream>
#include <fstream>

class Board{
    Square *theBoard[10][10];
    int level;
    int score;
    void clearBoard();
    std::string leftover;
public:
    Board();
    void init(std::ifstream &f);
    void init(int seed);    bool validMove(); //check if the move is valid
    void scramble();
    void hint(); //prints a square or return a move
    void mutateBoard(int x, int y, int c, char t, char s);
    void swap(int x, int y, char d);
    void fillBoard(int l);
    Square *getBoard();
    int getLevel();
    int getScore();
    void setLevel(int l);
    void setScore(int s);
    void setSeed(int seed);
    ~Board();
    friend std::ostream& operator<<(std::ostream &out, const Board &b);
};


#endif

