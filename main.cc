#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "square.h"
#include "board.h"
#include "basicsquare.h"
#include "board0.h"
#include "board1.h"
#include "board2.h"
#include "lateralsquare.h"
#include "psysquare.h"
#include "unstablesquare.h"
#include "uprightsquare.h"

using namespace std;

int main(int argc, char* argv[]) {
    string arg, file;
    Board *mainBoard = new Board0;
    int seed, level;
    stringstream ss;
    ifstream ff;
    for (int i = 1; i < argc; i++) {
        arg = argv[i];
        if (arg == "-seed") {
            i++;
            ss(argv[i]);
            ss >> seed;
            mainBoard->init(seed);
        }
        else if (arg == "-text") {}
        else if (arg == "-scriptfile") {
            i++;
            file = argv[i];
            ff(file.c_str());
            mainBoard->init(ff);
        }
        else if (arg == startlevel) {
            i++;
            level = argv[i];
            if (level == 1) {
                delete mainBoard;
                mainBoard = NULL;
                mainBoard = new Board1;
            }
            else if (level == 2) {
                delete mainBoard;
                mainBoard = NULL;   
                mainBoard = new Board2;
            }
        }
        else if (arg == "-testing") {}
    }
    string s;
    bool initialized = false;
    int x, y;
    char d;
    int level;
    while (cin >> s) {
        if (s == "swap") {
            cin >> x >> y >> d;
            mainBoard->swap(x, y, d);
        }
        else if (s == "hint") {
            if (!mainBoard.validMove()) {
                mainBoard->hint();
            }
        }
        else if (s ==  "scramble") {
            if (!mainBoard->validMove()) {
                mainBoard->scramble();
            }
        }
        else if (s == "levelup") {
            if (mainBoard->getLevel() == 0) {
                mainBoard = new Board1;
                                                                                                                                                                                                   }
            else if (mainBoard->getLevel() == 1) {
                mainBoard = new Board2;
            }
        }
        else if (s == "leveldown") {
            if (mainBoard->getLevel() == 2) {
                delete mainBoard;
                mainBoard = NULL;
                mainBoard = new Board1;
            }
            else if (mainBoard->getLevel() == 1) {
                delete mainBoard;
                mainBoard = NULL;
                mainBoard = new Board0;
            }
        }
        else if (s == "restart") {
            level = mainBoard->getLevel();
            delete mainBoard;
            mainBoard = NULL;
            if (level == 0) {
                mainBoard = new Board0;
            }
            else if (level == 1) {
                mainBoard = new Board1;
            }
            else {
                mainBoard = new Board2;
            }
        }
    }
}
