#include "Tiger.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


Tiger:: Tiger() {

}

Tiger:: Tiger(char* _name, int age) : Animal(_name, age) {

}

void Tiger:: makeSound() {
  printf("Sound from tiger, Name is %s and age is %d\n", name, age);
}

void Tiger:: eat() {
  printf("Tiger eat!\n");
}

Tiger:: ~Tiger() {

}
