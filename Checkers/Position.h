#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
 public:
  int x; //x coordinate
  int y; //y coordinate
  Position(int, int);
  ~Position();
  Position(const Position&);
  int getX();
  int getY();
  void setX(int);
  void setY(int);
  bool operator==(Position&); //over load ==
  Position topLeft(); //get the point to the top left
  Position topRight(); //get the point to the top right
  Position bottomLeft(); //get the point to the bottom left
  Position bottomRight(); //get the point to the bottom right
};

#endif
