#include <iostream>
#include <string>
// We saw in value initialization that if we don't have our own constructor and
// we initalize Entity e{} it will initialize everything to 0.
struct Entity {
  // One way is to define our own constructor
  Entity()
      : name{""}, pointer{nullptr}, x(2),
        y(23){}; // Notice here we can initailize things with {} or (), {} is
                 // safer, it won't bring any unexpected behaviour

  // Another way is to initalize vars in place
  std::string name{""};
  int *pointer{nullptr};
  int x{0}; // We cannot use () here though, C++ will interpret it as function
            // calls x() with one param and will try to look for implementation
            // of fucntion x in this class.
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