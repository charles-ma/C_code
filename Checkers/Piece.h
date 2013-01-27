#ifndef PIECE_H
#define PIECE_H

#include <iostream>

enum Side {black, red};
enum Kind {king, men};

class Piece {
 public:
  Side side;
  Kind kind;
  Piece(Side, Kind);
  ~Piece();
};

#endif
