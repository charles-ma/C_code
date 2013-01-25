#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Piece.h"

using namespace std;

class Board {

 private:
  Piece*** grid;

 public:
  Board();
  ~Board();
  void resp();
  Piece* getPiece(int, int);
  bool setPiece(int, int, Piece*);
};

#endif
