#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
 public:
  int x;
  int y;
  Position(int, int);
  ~Position();
  Position(const Position&);
  int getX();
  int getY();
  void setX(int);
  void setY(int);
  bool operator==(Position&);
  Position topLeft();
  Position topRight();
  Position bottomLeft();
  Position bottomRight();
};

#endif
