#include <iostream>
#include <string>

/*
Delegating Constructor:
----------------------
Delegating constructor means that let's say we have a constructor which runs
some algorithm x and then we define another constructor that also has to run
that same algortihm before it's own logic, then we don't need to write the logic
of that algorith in both constructors rather in second constructor we can
delegate the work to first, Let's see example
*/
struct Entity {

  Entity() : name{}, pointer{nullptr}, x(2), y(23) {
    name = std::to_string(x) +
           std::to_string(y); // sets default value for our name
    // Let's say this print statement is our alogrithm that we must run
    std::cout << " The name is : " << name << std::endl;
  };
  // Now let's say we have another constructor that needs to set x and y to new
  // values but keep same default name from above constructor.
  Entity(int _x, int _y)
      : Entity() { // Instead of writing the whole logic here again we delegated
                   // our work to constructor 1. This is way to write cleaner
                   // code.
    x = _x;
    y = _y;
  }
  std::string name{""};
  int *pointer{nullptr};
  int x{0};
  int y{0};
};

int main() {
  Entity e1{};
  std::cout << e1.name << std::endl;
  std::cout << e1.x << std::endl;
  std::cout << e1.y << std::endl;
  std::cout << e1.pointer << std::endl;

  return 0;
}