#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "Position.h"
#include <stdlib.h>
#include <ctime>

using namespace std;

void play(int);
bool makeStep(Side, int, int, int, int);
bool autoStep();

Board* board = new Board();

int main(int argc, char** argv) {
  int mode = -1;
  cout << "Please indicate the number of the players (1 or 2):" << endl;
  cin >> mode;
  if(mode == 1 || mode == 2)
    play(mode);
  else cout << "Wrong mode!" << endl;
}

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
	  if(makeStep(turn, x, y, des_x, des_y)) break;
	}
	turn = black;
      }
      else if(turn == black) {
	while(true) {
	  cout << "BLACK:" << endl;
	  cin >> x >> y >> des_x >> des_y;
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

bool makeStep(Side side, int x, int y, int des_x, int des_y) {
  if(board -> getPiece(x, y) == NULL) return false;
  if(board -> getPiece(x, y) -> side != side) return false;
  if(board -> move(x, y, des_x, des_y)) return true;
  return false;
}

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
