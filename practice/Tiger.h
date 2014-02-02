#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"

class Tiger: public Animal {
 public:
  Tiger();
  Tiger(char*, int);
  void makeSound();
  void eat();
  ~Tiger();
};

#endif
