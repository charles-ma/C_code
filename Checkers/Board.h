#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <list>
#include <cmath>
#include "Piece.h"
#include "Position.h"

using namespace std;

class Board {

 private:
  Piece*** grid;

 public:
  Board();
  ~Board();
  bool printBoard();
  Piece* getPiece(int, int);
  bool setPiece(int, int, Piece*);
  bool move(int, int, int, int);
  list<Position> getPath(Position, Position);
  Side checkWin();
  list<Piece*> getMovablePieces(Side);
 private:
  bool initBoard();
  bool findJumpPath(Position, Position, list<Position>*, Side, Kind);
  bool findMovePath(Position, Position, list<Position>*);
  bool isPhysicPos(Position);
  list<Position> findPossibleMove(Position);
  list<Position> findPossibleJump(Position, Position, Side, Kind);
};

#endif
