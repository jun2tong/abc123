#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "board.h"
#include "square.h"
using namespace std;

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

//initializer for Board0
void Board::init(ifstream &f){
    string aline;
    for(int i=0;i<10;i++){
        getline(f,aline);
        istringstream ss1(aline);
        for(int j=0;j<10;j++){
            int c;
            char s,t;
            ss1 >> s >> t >> c;
            theBoard[i][j] = new Square(i,j,c,s,t);
        }
    }
    f >> leftover;
}

//init for the board1 only, need to adjust again for the actual probability. Board0 is initialized using sequence.txt
void Board::init(int seed, int lvl){
    srand(seed);
    if(lvl==2){
    	int color;
    	for(int i=0;i<10;i++){
        	for(int j=0;j<10;j++){
        		color = rand()%5;
            	theBoard[i][j] = new Square(i,j,color,'_',t);
        	}
    	}
	}
	else if(lvl==1){
		
	}

// getters & setters
int Board::getScore() {
	return score;
}

void Board::setScore(int incr) {
	score += incr;
}

void Board::scramble(){
	Square *temp[10][10]; //might have memory issue here. by pass using vector or something
	int changed = 0;
	int i=0;
	int j = 0;
	while(changed < 100){
		r = rand()%10;
		c = rand()%10;
		if(temp[r][c]==NULL){
			int color = theBoard[i][j]->getColour();
			char spe = theBoard[i][j]->getSpecial();
			char typ = theBoard[i][j]->getType();
			temp[r][c] = new Square(r,c,color,spe,typ);
			delete [] theBoard[i][j];
			j++;
			if(j==10){
				j = 0;
				i++;
			}
			changed++;
		}
	}
	for(int r=0;r<10;r++){
		for(int c=0;c<10;c++){
			theBoard[r][c] = temp[r][c];
		}
	}
}

void Board::hint(){
	int first,second,third;
	//fix the first row
	for(int j=0;j<10;j++){
		if(j==0){
			first = theBoard[1][j]->getColour();
			second = theBoard[0][j+1]->getColour();
			third = theBoard[0][j+2]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			//second = theBoard[2][j]->getColour();
			thrid = theBoard[2][j]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
		}
		else if(j==1){
			first = theBoard[1][j]->getColour();
			second = theBoard[0][j+1]->getColour();
			third = theBoard[0][j-1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			third = theBoard[0][j+2]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			first = theBoard[0][j-1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			second = theBoard[1][j]->getColour();
			third = theBoard[2][j]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			first = theBoard[0][j+1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
		}
		else if(j==9){
			first = theBoard[1][j]->getColour();
			second = theBoard[0][j-1]->getColour();
			third = theBoard[0][j-2]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			second = theBoard[0][j-1]->getColour();
			third = theBoard[2][j]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
		}
		else if(j==8){
			first = theBoard[1][j]->getColour();
			second = theBoard[0][j+1]->getColour();
			third = theBoard[0][j-1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			second = theBoard[0][j-2]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			first = theBoard[0][j+1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			second = theBoard[1][j]->getColour();
			third = theBoard[2][j]->getColour();
			if(first==second&&second==third){
				cout <<  "0 " << j << endl;
				break;
			}
			first = theBoard[0][j-1]->getColour();
			if(first==second&&second==thrid){
				cout << "0 " << j << endl;
				break;
			}
		}
		else{
			first = theBoard[1][j]->getColour();
			second = theBoard[0][j+1]->getColour();
			third = theBoard[0][j-1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			second = theBoard[0][j-2]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			second = theBoard[0][j+1]->getColour();
			third = theBoard[0][j+2]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			second = theBoard[2][j]->getColour();
			third = theBoard[0][j+1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
			third = theBoard[0][j-1]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
		}
	}//done with first row
	//fix last row
	for(int j=0;j<10;j++){
		if(j==0){
			first = theBoard[8][j]->getColour();
			second = theBoard[9][j+1]->getColour();
			third = theBoard[9][j+2]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j+1]->getColour();
			second = theBoard[7][j]->getColour();
			thrid = theBoard[8][j]->getColour();
			if(first==second&&second==third){
				cout << "0 " << j << endl;
				break;
			}
		}
		else if(j==1){
			first = theBoard[8][j]->getColour();
			second = theBoard[9][j+1]->getColour();
			third = theBoard[9][j-1]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			third = theBoard[9][j+2]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j-1]->getColour();
			second = theBoard[8][j]->getColour();
			third = theBoard[7][j]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j+1]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
		}
		else if(j==9){
			first = theBoard[8][j]->getColour();
			second = theBoard[9][j-1]->getColour();
			third = theBoard[9][j-2]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j-1]->getColour();
			second = theBoard[8][j]->getColour();
			third = theBoard[7][j]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
		}
		else if(j==8){
			first = theBoard[8][j]->getColour();
			second = theBoard[9][j+1]->getColour();
			third = theBoard[9][j-1]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			second = theBoard[9][j-2]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j+1]->getColour();
			second = theBoard[8][j]->getColour();
			third = theBoard[7][j]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j-1]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
		}
		else{
			first = theBoard[8][j]->getColour();
			second = theBoard[9][j+1]->getColour();
			third = theBoard[9][j-1]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			second = theBoard[9][j-2]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			second = theBoard[9][j+1]->getColour();
			third = theBoard[9][j+2]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j+1]->getColour();
			second = theBoard[8][j]->getColour();
			third = theBoard[7][j]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
			first = theBoard[9][j-1]->getColour();
			if(first==second&&second==third){
				cout << "9 " << j << endl;
				break;
			}
		}
	}//done with last row
	//need to do the first and last column
	for(int i=1;i<9;i++){
		//check for horizontal match without border (mid)
		for(int j=1;j<9;j++){
			if(i==1&&j==1){
				//horizontal
				first = theBoard[i][j+1]->getColour();
				second = theBoard[i][j+2]->getColour();
				third = theBoard[i-1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j+1]->getColour();
				second = theBoard[i][j+2]->getColour();
				third = theBoard[i+1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j+1]->getColour();
				second = theBoard[i][j+2]->getColour();
				third = theBoard[i][j-1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				//vertical
				first = theBoard[i+1][j]->getColour();
				second = theBoard[i+2][j]->getColour();
				third = theBoard[i][j-1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i+1][j]->getColour();
				second = theBoard[i+2][j]->getColour();
				third = theBoard[i][j+1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i+1][j]->getColour();
				second = theBoard[i+2][j]->getColour();
				third = theBoard[i-1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
			}
			else if(i==1&&j==8){
				//horizontal
				first = theBoard[i][j-1]->getColour();
				second = theBoard[i][j-2]->getColour();
				third = theBoard[i-1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j-1]->getColour();
				second = theBoard[i][j-2]->getColour();
				third = theBoard[i+1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j-1]->getColour();
				second = theBoard[i][j-2]->getColour();
				third = theBoard[i][j+1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				//vertical
				first = theBoard[i+1][j]->getColour();
				second = theBoard[i+2][j]->getColour();
				third = theBoard[i-1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i+1][j]->getColour();
				second = theBoard[i+2][j]->getColour();
				third = theBoard[i][j+1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i+1][j]->getColour();
				second = theBoard[i+2][j]->getColour();
				third = theBoard[i][j+2]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
			}
			else if(i==8&&j==1){
				//horizontal
				first = theBoard[i][j+1]->getColour();
				second = theBoard[i][j+2]->getColour();
				third = theBoard[i-1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j+1]->getColour();
				second = theBoard[i][j+2]->getColour();
				third = theBoard[i+1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j+1]->getColour();
				second = theBoard[i][j+2]->getColour();
				third = theBoard[i][j-1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				//vertical
				first = theBoard[i-1][j]->getColour();
				second = theBoard[i-2][j]->getColour();
				third = theBoard[i][j-1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i-1][j]->getColour();
				second = theBoard[i-2][j]->getColour();
				third = theBoard[i][j+1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i-1][j]->getColour();
				second = theBoard[i-2][j]->getColour();
				third = theBoard[i+1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
			}
			else if(i==8&&j==8){
				//horizontal
				first = theBoard[i][j-1]->getColour();
				second = theBoard[i][j-2]->getColour();
				third = theBoard[i-1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j-1]->getColour();
				second = theBoard[i][j-2]->getColour();
				third = theBoard[i+1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i][j-1]->getColour();
				second = theBoard[i][j-2]->getColour();
				third = theBoard[i][j+1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				//vertical
				first = theBoard[i-1][j]->getColour();
				second = theBoard[i-2][j]->getColour();
				third = theBoard[i][j+1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i-1][j]->getColour();
				second = theBoard[i-2][j]->getColour();
				third = theBoard[i][j-1]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
				first = theBoard[i-1][j]->getColour();
				second = theBoard[i-2][j]->getColour();
				third = theBoard[i+1][j]->getColour();
				if(first==second&&second==third){
					cout << i << " " << j << endl;
					break;
				}
			}
			first = theBoard[i][j-1]->getColour();
			second = theBoard[i-1][j]->getColour();
			third = theBoard[i][j+1]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			second = theBoard[i+1][j]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			//check for vertical match without border (mid)
			first = theBoard[i-1][j]->getColour();
			second = theBoard[i][j+1]->getColour();
			third = theBoard[i+1][j]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			second = theBoard[i][j-1]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
		}
	}//end of a long ass loop
	
	//checking tail 3-match
	for(int i=2;i<7;i++){
		for(int j=2;j<7;i++){
			//north
			first = theBoard[i-2][j]->getColour();
			second = theBoard[i-1][j]->getColour();
			third = theBoard[i][j-1]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			third = theBoard[i][j+1]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			//south
			first = theBoard[i+2][j]->getColour();
			second = theBoard[i+1][j]->getColour();
			third = theBoard[i][j-1]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			third = theBoard[i][j+1]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			//east
			first = theBoard[i][j+1]->getColour();
			second = theBoard[i][j+2]->getColour();
			third = theBoard[i-1][j]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			third = theBoard[i+1][j]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			//west
			first = theBoard[i][j-1]->getColour();
			second = theBoard[i][j-2]->getColour();
			third = theBoard[i-1][j]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
			third = theBoard[i+1][j]->getColour();
			if(first==second&&second==third){
				cout << i << " " << j << endl;
				break;
			}
		}
	}
	
}

void Board::swap(int r, int c, char z) {
	int tempColor;
	int newR, newC;
	char tempType, tempSpecial;
	bool locked1;
	if (z == 0) { //north
		newR = r-1;
		newC = c;
	}
	else if (z == 1) { //south
		newR = r + 1
		newC = c;
	}
	else if (z == 2) { //west
		newR = r;
		newC = c - 1;
	}
	else if (z == 3) { //east
		newR = r;
		newC = c + 1;
	}
	//swap the sqaures 
	tempColor = mainBoard[r][c]->getColour();
	tempType = mainBoard[r][c]->getType();
	tempSpecial = mainBoard[r][c]->getSpecial();
	locked1 = mainBoard[r][c]->getLocked();

	delete mainBoard[r][c];
	mainBoard[r][c] = new Square(r, c, mainBoard[newR][newC]->getColour(),mainBoard[newR][newC]->getType, mainBoard[newR][newC]->special);
	mainBoard[r][c]->setLocked(mainBoard[newR][newC]->getLocked());
	mainBoard[r-1][y]->setPosition(newR, newC);

	delete mainBoard[newR][newC];
	mainBoard[r-1][y] = new Square(newR, newC, tempColour, tempType, tempSpecial);
	mainBoard[r-1][y]->setLocked(locked1);
	mainBoard[r-1][y]->setPosition(newR, newC);

	if (checkMatch()) {
		resolveMatches();
	}
}

bool Board::checkMatch() {
	// check for match of 3 in the board 
	int color1, color2, color3;
	// check all rows for row of 3 squares of same colour
	for (int i=0; i < 10; i++) {
		for (int j=0; j < 8; j++) {
			color1 = theBoard[i][j];
			color2 = theBoard[i][j+1];
			color3 = theBoard[i][j+2];
			if (color1 == color2 && color2 == color3) {
				return true;
			}
		}
	}
	// check all coloumns for col of 3 squares of same color
	for (int j=0; j<10: j++) {
		for (int i=0; i<8; i++) {
			color1 = theBoard[i][j];
			color2 = theBoard[i+1][j];
			color3 = theBoard[i + 2][j];
			if (color1 == color2 && color2 == color3) {
				return true;
			}
		}
	}
	return false;
}

// check for 5 match horizontally
void Board::check5Row() {
	int color1, color2, color3, color4, color5;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int i=9; i != -1; i--) {
		for (int j=0; j < 6; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i][j+1]->getColour();
			color3 = theBoard[i][j+2]->getColour();
			color4 = theBoard[i][j+3]->getColour();
			color5 = theBoard[i][j+4]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 5; k++) {
					if (theBoard[i][j+k]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j+k]->type == 'u') { 
						upright = true;
						uprightC = j+k;
					}
					else if (theBoard[i][j+k]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i][j+k]->type == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('-'); // set squares to '-' type
				theBoard[i][j+1]->setType('-');
				theBoard[i][j+2]->setType('p'); // set center square to 'p' type
				theBoard[i][j+3]->setType('-');
				theBoard[i][j+4]->setType('-');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

// check for 5 match vertically
void Board::check5Column() {
	int color1, color2, color3, color4, color5;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int i=5; i != -1; i--) {
		for (int j=0; j < 10; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i+3][j]->getColour();
			color5 = theBoard[i+4][j]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 5; k++) {
					if (theBoard[i+k][j]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+k][j]->type == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+k][j]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+k][j]->type == 'l') {
						lateral = true;
						lateralR = i+k;
					}
				}
				theBoard[i][j]->setType('-'); // set squares to '-' type
				theBoard[i+1][j]->setType('-');
				theBoard[i+2][j]->setType('p'); // set center square to 'p' type
				theBoard[i+3][j]->setType('-');
				theBoard[i+4][j]->setType('-');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

// check for 4 match horizontally
void Board::check4Row() {
	int color1, color2, color3, color4;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int i=9; i != -1; i--) {
		for (int j=0; j < 7; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i][j+1]->getColour();
			color3 = theBoard[i][j+2]->getColour();
			color4 = theBoard[i][j+3]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 4; k++) {
					if (theBoard[i][j+k]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j+k]->type == 'u') { 
						upright = true;
						uprightC = j+k;
					}
					else if (theBoard[i][j+k]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i][j+k]->type == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('-'); // set squares to '-' type
				theBoard[i][j+1]->setType('l'); // set type to 'l' type
				theBoard[i][j+2]->setType('-');
				theBoard[i][j+3]->setType('-');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

// check for 4 match vertically
void Board::check4Column() {
	int color1, color2, color3, color4;
	// keep track of whether one of the squares involved in the match was a different type of square 
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match then keep track of it's row
				// to later rid all those cells in that row
	// check all rows for row of 5 squares of same color
	for (int i=6; i != -1; i--) {
		for (int j=0; j < 10; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i+3][j]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4) { //check for match
				// check if any of the squares in the match are a different type
				for (int k=0; k < 4; k++) {
					if (theBoard[i+k][j]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+k][j]->type == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+k][j]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+k][j]->type == 'l') {
						lateral = true;
						lateralR = i+k;
					}
				}
				theBoard[i][j]->setType('-'); // set squares to '-' type
				theBoard[i+1][j]->setType('-');
				theBoard[i+2][j]->setType('l'); // set square to 'l' type
				theBoard[i+3][j]->setType('-');
				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

void Board::checkL1() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 7; i != -1; i--) {
		for (int j =0; j<8; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i][j+1]->getColour();
			color5 = theBoard[i][j+2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i+i2][j]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+i2][j]->type == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+i2][j]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+i2][j]->type == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=0; j2 < 2; j2++) {
					if (theBoard[i][j + j2]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j + j2]->type == 'u') {
						upright = true;
						uprightC = j + j2;
					}
					else if (theBoard[i][j+j2]->type == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j+j2]->type == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); //set to unstable square
				theBoard[i+1][j]->setType('-');
				theBoard[i+2][j]->setType('-');
				theBoard[i][j+1]->setType('-');
				theBoard[i][j+2]->setType('-');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

void Board::checkL2() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 9; i > 1; i--) {
		for (int j =0; j<8; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i-1][j]->getColour();
			color3 = theBoard[i-2][j]->getColour();
			color4 = theBoard[i][j+1]->getColour();
			color5 = theBoard[i][j+2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i-i2][j]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i-i2][j]->type == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i-i2][j]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i-i2][j]->type == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=1; j2 < 3; j2++) {
					if (theBoard[i][j + j2]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j + j2]->type == 'u') {
						upright = true;
						uprightC = j + j2;
					}
					else if (theBoard[i][j+j2]->type == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j+j2]->type == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); //set to unstable square
				theBoard[i-1][j]->setType('-');
				theBoard[i-2][j]->setType('-');
				theBoard[i][j+1]->setType('-');
				theBoard[i][j+2]->setType('-');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

void Board::checkL3() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 9; i > 1; i--) {
		for (int j =2; j<10; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i-1][j]->getColour();
			color3 = theBoard[i-2][j]->getColour();
			color4 = theBoard[i][j-1]->getColour();
			color5 = theBoard[i][j-2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i-i2][j]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i-i2][j]->type == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i-i2][j]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i-i2][j]->type == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=1; j2 < 3; j2++) {
					if (theBoard[i][j - j2]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j - j2]->type == 'u') {
						upright = true;
						uprightC = j - j2;
					}
					else if (theBoard[i][j-j2]->type == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j-j2]->type == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); //set to unstable square
				theBoard[i-1][j]->setType('-');
				theBoard[i-2][j]->setType('-');
				theBoard[i][j-1]->setType('-');
				theBoard[i][j-2]->setType('-');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

void Board::checkL4() { // check first L shape 
	int color1, color2, color3, color4, color5;
	bool psychedelic = false;
	bool unstable = false;
	bool upright = false;
	bool lateral = false;
	int uprightC; // if an uprightSquare is involved in a match then keep track of it's column 
				  // to later rid all those cells in that column 
	int lateralR; // if a lateralSquare is involved in a match
	for (int i = 7; i != -1; i--) {
		for (int j =2; j<10; j++) {
			color1 = theBoard[i][j]->getColour();
			color2 = theBoard[i+1][j]->getColour();
			color3 = theBoard[i+2][j]->getColour();
			color4 = theBoard[i][j-1]->getColour();
			color5 = theBoard[i][j-2]->getColour();
			if (color1 == color2 && color2 == color3 && color3 == color4 && color4 == color5) { //check for match
				// check if any of the squares in the match are a different type
				for (int i2=0; i2 < 3; i2++) {
					if (theBoard[i+i2][j]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i+i2][j]->type == 'u') { 
						upright = true;
						uprightC = j;
					}
					else if (theBoard[i+i2][j]->type == 'b') { // unstable square involved
						unstable = true;
					}
					else if (theBoard[i+i2][j]->type == 'l') {
						lateral = true;
						lateralR = i+i2;
					}
				}
				for (int j2=1; j2 < 3; j2++) {
					if (theBoard[i][j - j2]->type == 'p') {
						psychedelic = true;
					}
					else if (theBoard[i][j - j2]->type == 'u') {
						upright = true;
						uprightC = j - j2;
					}
					else if (theBoard[i][j-j2]->type == 'b') {
						unstable = true;
					}
					else if (theBoard[i][j-j2]->type == 'l') {
						lateral = true;
						lateralR = i;
					}
				}
				theBoard[i][j]->setType('b'); //set to unstable square
				theBoard[i+1][j]->setType('-');
				theBoard[i+2][j]->setType('-');
				theBoard[i][j-1]->setType('-');
				theBoard[i][j-2]->setType('-');

				if (psychdelic == true) {// if psychedelic square was involved in the match
					// set all squares in the board of same color to '-' type
					for (int i2=0; i2 < 10; i2++) {
						for (int j2=0; j2 < 10; j2++) {
							if (theBoard[i][j]->colour == color1) {
								theBoard[i][j]->setType('-');
							}
						}
					}
				}
				else if (upright == true) {
					for (int j3 = 0; j < 10; j++) { // set the entire column to type '-'
						theBoard[j3][uprightC]->setType('-');
					}
				}
				else if (lateral == true) {
					for (int i3=0; i3<10; i3++) { // set the entire row to type '-'
						theBoard[lateralR][i3]->setType('-')
					}
				}
			}
		}
	}
}

void Board::resolveMatches() {
	while (checkMatch()) {
		check5Row();
		check5Column();
		check4Row();
		check4Column();
		checkL1();
		checkL2();
		checkL3();
		checkL4();
	}
	// add method to fill in all the squares with '-' type
}

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

