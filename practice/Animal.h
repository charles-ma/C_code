#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
 public:
  char* name;
  int age;
  
  Animal();
  Animal(char*, int);
  virtual void makeSound();
  virtual void eat() = 0;
  ~Animal();
};

#endif
