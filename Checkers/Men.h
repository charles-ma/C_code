#ifndef MEN_H
#define MEN_H

#include <iostream>
#include "Piece.h"

class Men: public Piece {
 public:
  Men(Side, Board*);
  ~Men();
  bool move(int, int);
};

#endif
