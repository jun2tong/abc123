#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <fstream>
#include "square.h"

class Board{
    Square *theBoard[10][10];
    int level;
    int score;
    void clearBoard();
    std::string leftover;
public:
    Board();
    void init(std::ifstream &f); // Jun will do it now
    void init(int seed); // Jun will do it now
    
    bool validMove(); //check if the move is valid (do not have it yet)
    
    void swap(int r, int c, char d); 
    bool checkMatch(); // checks whether there exists a row of 3 or column of 3 of the same color
    void resolveMatch();
    void check5Row();
    void check5Column();
    void check4Row();
    void check4Column();
    void checkL1();
    void checkL2();
    void checkL3();
    void checkL4();
    
    void scramble();
    void updateBoard(); // recursive function that is called after a swap is made to fill in the board and check for matches
    void hint(); //prints a square or return a move 
    void mutateBoard(int r, int c, int c, char t, char s);
    
    Square *getBoard();
    int getLevel(); //amber
    int getScore(); //amber
    void setScore(int s); //amber
    ~Board();
    friend std::ostream& operator<<(std::ostream &out, const Board &b);
};


#endif

