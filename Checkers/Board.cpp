#include <iostream>
#include "Board.h"

bool Board:: printBoard() {
  //  cout << "---------y" << endl;
  for(int i = 0; i < 9; i++) {
    cout << i;
  }
  cout << "y" << endl;
  for(int i = 1; i < 9; i++) {
    cout << i;
    for(int j = 1; j < 9; j++) {
      if(getPiece(i, j) == NULL) cout << " ";
      else {
	if(getPiece(i, j) -> side == red && getPiece(i, j) -> kind == men) cout << "+";
	if(getPiece(i, j) -> side == black && getPiece(i, j) -> kind == men) cout << "*";
	if(getPiece(i, j) -> side == red && getPiece(i, j) -> kind == king) cout << "@";
	if(getPiece(i, j) -> side == black && getPiece(i, j) -> kind == king) cout << "$";
      }
    }
    cout << "" << endl;
  }
  cout << "x" << endl; 
  return true;
}

Board:: Board() {
  grid = new Piece**[8];
  for(int i = 0; i < 8; i++) {
    Piece** a = new Piece*[8];
    for(int j = 0; j < 8; j++) {
      a[j] = NULL;
    }
    grid[i] = a;
  }
  initBoard();
}

Board:: ~Board() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(grid[i][j] != NULL) delete grid[i][j];
    }
    delete grid[i];
  }
  delete grid;
}

bool Board:: initBoard() {
  for(int x = 8; x != 5; x--) {
    for(int y = 1; y != 9; y++) {
      if((x + y) % 2 != 0) {
	Piece *p = new Piece(red, men);
	setPiece(x, y, p);
      }
    }
  }
  for(int x = 1; x != 4; x++) {
    for(int y = 1; y != 9; y++) {
      if((x + y) % 2 != 0) {
	Piece *p = new Piece(black, men);
	setPiece(x, y, p);
      }
    }
  }
  return true;
}

bool Board:: move(int x, int y, int des_x, int des_y) {
  Position startPos(x, y);
  Position endPos(des_x, des_y);
  Piece* piece = getPiece(x, y);
  Side side = piece -> side;
  list<Position> path = getPath(startPos, endPos);
  list<Position> :: iterator i;
  if(path.size() == 0) return false;
  if(path.size() == 2 && abs(des_x - x) == 1 && abs(des_y - y) == 1) {
    if(side == red && des_x == 1) piece -> kind = king;
    if(side == black && des_x == 8) piece -> kind = king;
    setPiece(startPos.x, startPos.y, NULL);
    setPiece(endPos.x, endPos.y, piece);
    return true;
  }
  i = path.begin();
  for(; i != path.end(); i++) {
    int x1 = (*i).x;
    int y1 = (*i).y;
    int x2, y2;
    i++;
    if(i != path.end()) {
      x2 = (*i).x;
      y2 = (*i).y;
      setPiece((x1 + x2) / 2, (y1 + y2) / 2, NULL);
    }
    i--;
  }
  if(side == red && des_x == 1) piece -> kind = king;
  if(side == black && des_x == 8) piece -> kind = king;
  setPiece(startPos.x, startPos.y, NULL);
  setPiece(endPos.x, endPos.y, piece);
  return true;
}

Piece* Board:: getPiece(int x, int y) {
  if(x <= 8 && x > 0 && y <= 8 && y > 0)
    return grid[x - 1][y - 1];
  return NULL;
}

bool Board:: setPiece(int x, int y, Piece* piece) {
  if(x >= 1 && x <=8 && y >=1 && y <= 8)
    grid[x - 1][y - 1] = piece;
  else return false;
  return true;
}

bool Board:: findJumpPath(Position startPos, Position endPos, list<Position>* possiblePos, Side side, Kind kind) {
  possiblePos -> push_back(startPos);
  list<Position> :: reverse_iterator i;
  Position lastPos = Position(0, 0);
  i = possiblePos -> rbegin();
  i--;
  if(i != possiblePos -> rend()) lastPos = *i;
  list<Position> possibles = findPossibleJump(startPos, lastPos, side, kind);
  if(startPos == endPos) {
    if(possibles.size() == 0) return true;
    else{
      possiblePos -> pop_back();
      return false;
    }
  }
  else if(possibles.size() == 0) {
    possiblePos -> pop_back();
    return false;
  }
  else {
    list<Position> :: iterator j;
    for(j = possibles.begin(); j != possibles.end(); j++) {
      if(findJumpPath(*j, endPos, possiblePos, side, kind)) return true;
    }
    possiblePos -> pop_back();
    return false;
  }
}

list<Position> Board:: getPath(Position startPos, Position endPos) {
  list<Position> result;
  if(endPos.x > 8 || endPos.y > 8 || endPos.x <= 0 || endPos.y <= 0 || startPos == endPos) return result;
  Piece* p = getPiece(startPos.x, startPos.y);
  if(p == NULL) return result;
  if(findJumpPath(startPos, endPos, &result, p -> side, p -> kind))
    return result;
  result.clear();
  if(findMovePath(startPos, endPos, &result))
    return result;
  result.clear();
  return result;
}

bool Board:: findMovePath(Position startPos, Position endPos, list<Position>* possiblePos) {
  list<Position> result = findPossibleMove(startPos);
  list<Position>:: iterator i;
  if(result.size() == 0) return false;
  for(i = result.begin(); i != result.end(); i++) {
    if(endPos == *i) {
      possiblePos -> push_back(startPos);
      possiblePos -> push_back(endPos);
    }
  }
  return true;
}

list<Position> Board:: findPossibleMove(Position point) {
  list<Position> result;
  Piece* p = getPiece(point.x, point.y);
  if(p == NULL) return result;
  if(p -> kind == king) {
    if(isPhysicPos(point.topLeft()))
      result.push_back(point.topLeft());
    if(isPhysicPos(point.topRight()))
      result.push_back(point.topRight());
    if(isPhysicPos(point.bottomLeft()))
      result.push_back(point.bottomLeft());
    if(isPhysicPos(point.bottomRight()))
      result.push_back(point.bottomRight());
  }
  if(p -> kind == men) {
    if(p -> side == red) {
      if(isPhysicPos(point.topLeft()))
	result.push_back(point.topLeft());
      if(isPhysicPos(point.topRight()))
	result.push_back(point.topRight());
    }
    else if(p -> side == black) {
      if(isPhysicPos(point.bottomLeft()))
	result.push_back(point.bottomLeft());
      if(isPhysicPos(point.bottomRight()))
	result.push_back(point.bottomRight());
    }
  }
  return result;
}

list<Position> Board:: findPossibleJump(Position point, Position last, Side side, Kind kind) {
  list<Position> result;
  int x = point.x;
  int y = point.y;
  
  if(kind == king || (kind == men && side == black)){
    if(getPiece(x + 1, y + 1) != NULL && getPiece(x + 1, y + 1) -> side != side && isPhysicPos(Position(x + 2, y + 2)))
      result.push_back(point.bottomRight().bottomRight());
    if(getPiece(x + 1, y - 1) != NULL && getPiece(x + 1, y - 1) -> side != side && isPhysicPos(Position(x + 2, y - 2)))
      result.push_back(point.bottomLeft().bottomLeft());
  }else if(kind == king || (kind == men && side == red)) {
    if(getPiece(x - 1, y + 1) != NULL && getPiece(x - 1, y + 1) -> side != side && isPhysicPos(Position(x - 2, y + 2)))
      result.push_back(point.topRight().topRight());
    if(getPiece(x - 1, y - 1) != NULL && getPiece(x - 1, y - 1) -> side != side && isPhysicPos(Position(x - 2, y - 2)))
      result.push_back(point.topLeft().topLeft());
  }
  return result;
}

bool Board:: isPhysicPos(Position point) {
  if(point.x > 8 || point.y > 8 || point.x <= 0 || point.y <= 0 || getPiece(point.x, point.y) != NULL) return false;
  return true;
}

Side Board:: checkWin() {
  int redNum = 0;
  int blackNum = 0;
  for(int i = 1; i < 9; i++)
    for(int j = 1; j < 9; j++)
      if(getPiece(i, j) != NULL){
	Piece* p = getPiece(i, j);
	Position pos = Position(i, j);
	Position last = Position(0, 0);
	if(p -> side == red && (findPossibleMove(pos).size() != 0 || findPossibleJump(pos, last, p -> side, p -> kind).size() != 0))
	  redNum++;
	if(p -> side == black && (findPossibleMove(pos).size() != 0 || findPossibleJump(pos, last, p -> side, p -> kind).size() != 0))
	  blackNum++;
      }
  if(redNum == 0) return black;
  if(blackNum == 0) return red;
  return white;
}

list<Piece*> Board:: getMovablePieces(Side side) {
  list<Piece*> result;
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++){
      Position last = Position(0, 0);
      if(grid[i][j] != NULL && grid[i][j] -> side == side && (findPossibleMove(Position(i + 1, j + 1)).size() != 0 || findPossibleJump(Position(i + 1, j + 1), last, grid[i][j] -> side, grid[i][j] -> kind).size() != 0))
	result.push_back(grid[i][j]);
    }
  return result;
}
