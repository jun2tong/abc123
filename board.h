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
    int leftoverLen;
    int numGenerated;
public:
    Board();
    void init(std::ifstream &f); //jun
    void init(int seed); //jun
    bool validMove(int r, int c, char d); //check if the move is valid
                                        // amber
    void scramble(); // jun
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
    void checkL4()
    
    virtual void updateBoard() = 0; // recursive function that is called after a swap is made to fill in the board and check for matches
                    // amber -> do for Board0.cc
    void hint(); //prints a square or return a move
                //jun
    void swap(int r, int c, char d);
    void fillBoard(int l);
    Square *getBoard();
    int getScore();
    void setLevel(int l);
    void setScore(int s);
    void setSeed(int seed);
    ~Board();
    friend std::ostream& operator<<(std::ostream &out, const Board &b);
};


#endif

