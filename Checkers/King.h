#ifndef KING_H
#define KING_H

#include <iostream>
#include "Piece.h"

class King: public Piece {
 public:
  King(Side, Board*);
  ~King();
  bool move(int, int);
};

#endif
