#include "grid.h"
#include <iostream>
#include <fstream>

#include <string>
//#include "board.h"
#include "cell.h"
using namespace std;

//class Board{
//  Square *theBoard[10][10];
//  int level;
//  int score;
void Grid::clearBoard(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            delete theBoard[i][j];
            theBoard[i][j] = NULL;
        }
    }
}

//public:
Grid::Board():level(0),score(0){}

Gird::Board(ifstream &f):level(0),score(0){
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


