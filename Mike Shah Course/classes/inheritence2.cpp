#include <iostream>
#include <string>

class TopLevel {
public:
  TopLevel(std::string n) { std::cout << "Top Level constuctor" << std::endl; }
};
class Base : public TopLevel {

public:
  Base()
      : TopLevel("Default") { // Have to do this bcz TopLevel class have no
                              // default constructor.
    std::cout << "Base Class Constructor" << std::endl;
  }
  Base(std::string n) : TopLevel("Defalult"), name(n) {
    std::cout << "Base Class(name) Constructor" << std::endl;
  }
  ~Base() { std::cout << "Base Class Destructor" << std::endl; }

private:
  std::string name;
};
class Derived : public Base {
public:
  Derived() : Base("Defualt") {
    std::cout << "Derived class Constructor" << std::endl;
  }
  ~Derived() { std::cout << "Derived class Destructor" << std::endl; }
};
int main() {
  Derived v;
  // If we instead do
  Derived v2; // this won't work if we don't change the Derived
              // constructor as above
              /*
              Summary:
              ---------
              1. When defining the constructors we have to see in Base classes how to
              initalize them
              2. If Base classes have custom constructors, they have to be taken cared of
              when initilizing derived classes.
              */
  return 0;
}