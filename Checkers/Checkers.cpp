#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Position.h"
#include <stdlib.h>
#include <ctime>
#include <fstream>

using namespace std;

void play(int);
bool makeStep(Side, int, int, int, int);
bool autoStep();
bool saveState();
bool openState();
bool playScript();

Board* board = new Board();

//main function
int main(int argc, char** argv) {
  int mode = -1;
  char answer = 'n';
  cout << "Do you want to load game from existing file?(y or other):" << endl;
  cin >> answer;
  if(answer == 'y') openState();
  cout << "Do you want to play with scripts?(y or other):" << endl;
  cin >> answer;
  if(answer == 'y') playScript(); 
  else {
    cout << "Please indicate the number of the players (1 or 2):" << endl;
    cin >> mode;
    if(mode == 1 || mode == 2)
      play(mode);
    else cout << "Wrong mode!" << endl;
  }
}

//play the game in a certain mode
void play(int mode) {
  board -> printBoard();
  Side turn = red;
  int x, y, des_x, des_y;
  if(mode == 1) {
    while(board -> checkWin() == white) {
      if(turn == red) {
	while(true) {
	  cout << "RED:" << endl;
	  cin >> x >> y >> des_x >> des_y;
	  if(x == 0 && y == 0 && des_x == 0 && des_y == 0) saveState();
	  if(makeStep(turn, x, y, des_x, des_y)) break;
	}
	turn = black;
      }
      else if(turn == black) {
	autoStep();
	turn = red;
      }
      board -> printBoard();
    }
    if(board -> checkWin() == red) cout << "RED WIN!" << endl;
    if(board -> checkWin() == black) cout << "BLACK WIN!" << endl;
  } else if(mode == 2) {
    while(board -> checkWin() == white) {
      if(turn == red) {
	while(true) {
	  cout << "RED:" << endl;
	  cin >> x >> y >> des_x >> des_y;
	  if(x == 0 && y == 0 && des_x == 0 && des_y == 0) saveState();
	  if(makeStep(turn, x, y, des_x, des_y)) break;
	}
	turn = black;
      }
      else if(turn == black) {
	while(true) {
	  cout << "BLACK:" << endl;
	  cin >> x >> y >> des_x >> des_y;
	  if(x == 0 && y == 0 && des_x == 0 && des_y == 0) saveState();
	  if(makeStep(turn, x, y, des_x, des_y)) break;
	}
	turn = red;
      }
      board -> printBoard();
    }
    if(board -> checkWin() == red) cout << "RED WIN!" << endl;
    if(board -> checkWin() == black) cout << "BLACK WIN!" << endl;
  }
}

//make a step in the game
bool makeStep(Side side, int x, int y, int des_x, int des_y) {
  if(board -> getPiece(x, y) == NULL) return false;
  if(board -> getPiece(x, y) -> side != side) return false;
  if(board -> move(x, y, des_x, des_y)) return true;
  return false;
}

//generate a step automatically
bool autoStep() {
  list<Piece*> blackPieces;
  blackPieces = board -> getMovablePieces(black);
  if(blackPieces.size() == 0) return false;
  list<Piece*> :: iterator i;
  srand((int) time(0));
  int ranNum = rand() % blackPieces.size();
  i = blackPieces.begin();
  for(int j = 0; j < ranNum; j++) {
    i++;
  }
  Piece* p = *i;
  int x = 0,y = 0;
  for(int k = 1; k <= 8; k++)
    for(int l = 1; l <= 8; l++)
      if(board -> getPiece(k, l) == p) {
	x = k;
	y = l;
      } 
  for(int k = 1; k <= 8; k++)
    for(int l = 1; l <= 8; l++)
      if(makeStep(p -> side, x, y, k, l)) return true;
  return false;
}

//save the state of the game as a file
bool saveState() {
  char* fileName = new char[100];
  cout << "Please indicate a file name:" << endl;
  cin >> fileName;
  ofstream saveFile;
  while(true) {
    saveFile.open(fileName, ios::in | ios::out);
    if(saveFile.is_open()) {
      cout << "file already exists! Choose another one!" << endl;
      cin >> fileName;
      saveFile.close();
    } else {
      saveFile.close();
      saveFile.open(fileName);
      break;
    }
  }
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      int code = 0;
      Piece * piece = board -> getPiece(i, j);
      if(piece == NULL) code = 0;
      else if(piece -> side == red && piece -> kind == men) code = 1;
      else if(piece -> side == red && piece -> kind == king) code = 2;
      else if(piece -> side == black && piece -> kind == men) code = 3;
      else code = 4;
      saveFile << code;
    }
  }
  saveFile.close();
  cout << "File saved!" << endl;
}

//restore the state of a game
bool openState() {
  char* fileName = new char[100];
  cout << "Please indicate a file name:" << endl;
  cin >> fileName;
  ifstream openFile;
  while(true) {
    openFile.open(fileName, ios::in);
    if(!openFile.is_open()) {
      cout << "file does not exist! Choose another one!" << endl;
      cin >> fileName;
      openFile.close();
    } else {
      break;
    }
  }
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      int code = 0;
      code = openFile.get() - 48;
      Piece * piece = new Piece(red, men);
      if(code == 0) piece = NULL;
      else if(code == 1) {
	piece -> side = red;
	piece -> kind = men;
      } else if(code == 2) {
	piece -> side = red;
	piece -> kind = king;
      } else if(code == 3) {
	piece -> side = black;
	piece -> kind = men;
      } else {
	piece -> side = black;
	piece -> kind = king;
      }
      board -> setPiece(i, j, piece);
    }
  }
  openFile.close();
  board -> printBoard();
  cout << "File opened!" << endl;
}

//play with scripts
bool playScript() {
  char* fileName = new char[100];
  cout << "Please indicate a script name:" << endl;
  cin >> fileName;
  ifstream openFile;
  while(true) {
    openFile.open(fileName, ios::in);
    if(!openFile.is_open()) {
      cout << "file does not exist! Choose another one!" << endl;
      cin >> fileName;
      openFile.close();
    } else {
      break;
    }
  }
  int code = 0;
  int coordi[4] = {0, 0, 0, 0};
  int i = 0;
  Side turn = red;
  while(!openFile.eof()) {
    code = openFile.get() - 48;
    coordi[i % 4] = code;
    if(i % 4 == 3) {
      makeStep(turn, coordi[0], coordi[1], coordi[2], coordi[3]);
      if(turn == red) turn = black;
      else if(turn == black) turn = red;
      board -> printBoard();
    } 
    i++;
  }
  openFile.close();
  board -> printBoard();
}
