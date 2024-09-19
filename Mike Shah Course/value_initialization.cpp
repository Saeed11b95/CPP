#include <iostream>
#include <string>

struct Entity {
  std::string name;
  int *pointer;
  int x;
  int y;
};

int main() {
  Entity e;
  std::cout << e.name << std::endl;    //
  std::cout << e.x << std::endl;       // 1651076199
  std::cout << e.y << std::endl;       // 779647075
  std::cout << e.pointer << std::endl; // 0x2e78786362696c67
  // We notice string is ok, it's empty as expected but for ints, c++ will have
  // what ever was stored at that memory before it was allocated for x and y.
  // Everytime program runs this will keep changing.

  // What is the Solution:
  //=====================
  // 1. One solution is to initialize with {} braces but if we have defined a
  // constructor with no arguments this e1{} will call that constructor and
  // depending on inplementation of our constructor it may or may not work, i.e
  // If we define our constructor we have to make sure everything is initialized
  // properly. Therefore {} will only work with default constructors.
  Entity e1{};
  std::cout << e1.name << std::endl;    //
  std::cout << e1.x << std::endl;       // 0
  std::cout << e1.y << std::endl;       // 0
  std::cout << e1.pointer << std::endl; // 0 This zero means nullptr
  // 2. Sencond solution is to create appropriate constructor and initialize
  // values properly.

  return 0;
}