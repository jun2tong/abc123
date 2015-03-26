#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "board.h"
#include "square.h"
using namespace std;

//class Board{
//  Square *theBoard[10][10];
//  int level;
//  int score;
void Board::clearBoard(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            delete theBoard[i][j];
            theBoard[i][j] = NULL;
        }
    }
}

//public:
Board::Board():level(0),score(0){}

Board::Board(ifstream &f):level(0),score(0){
    string aline;
    for(int i=0;i<10;i++){
        getline(f,aline);
        cout << aline << " this is aline" << endl;
        istringstream ss1(aline);
        for(int j=0;j<10;j++){
            int c;
            char s,t;
            ss1 >> s >> t >> c;
            theBoard[i][j] = new Square(i,j,c,s,t);
        }
    }
    f >> leftover;
    cout << leftover << endl;
}


//  Board(int seed);
//  bool validMove(); //check if there are anymore moves left
//  void scramble();
//  void hint(); //prints a square or return a move
//  void mutateBoard(int x, int y, int c, char t=0, char s=0);
//  void swap(int x, int y, char d);
//  void fillBoard(int l);
//  Square getBoard();
//  int getLevel();
//  int getScore();
//  void setLevel(int l);
//  void setScore(int s);

Board::~Board(){
    clearBoard();
//  delete theBoard;
}

ostream& operator<<(ostream &out, const Board &b){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            out << *(b.theBoard[i][j]) << " ";
        }
        out << endl;
    }
    return out;
}

