#include <iostream>
#include <string>

class Base {

public:
  Base() { std::cout << "Base Class Constructor" << std::endl; }
  ~Base() { std::cout << "Base Class Destructor" << std::endl; }
  virtual void Print() {
    std::cout << "Hello There! (Base)" << std::endl;
  } // Virtual keyword is sort of abstract method

private:
  std::string name;
};
class Derived : public Base {
public:
  Derived() { std::cout << "Derived class Constructor" << std::endl; }
  ~Derived() { std::cout << "Derived class Destructor" << std::endl; }
  void Print() override {
    std::cout << "Hello There! (Derived)" << std::endl;
  } // Overriding the Base class print, this override key word is optional, it
    // will work without it aswell but recommended for predictable behaviour
};
int main() {
  Derived v;
  v.Print(); // Hello There! (Derived), It calls the correct one
  // But what if we initialize out object using pointer.
  Base *instance = new Derived;
  instance->Print(); // This calls the Base, Although we initialized Derived,
                     // The reason is that out pointer is of base type and it
                     // can store all derived types.
  // To make it work we have to mark Base function as "virtual" and the override
  // in Derived, It is quite similar to Abstract mehtod in Python.
  // Now what if we want to call the base method on derived instance?
  instance->Base::Print(); // Hello There! (Base)
  delete instance;
  return 0;
}