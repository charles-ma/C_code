#include <iostream>
#include "Board.h"
#include "Piece.h"

using namespace std;

int main(int argc, char** argv) {
  cout << "hello world" << endl;
  Board board;
  Piece* piece = new Piece(red);
  board.setPiece(1, 1, piece);
  board.resp();
}
