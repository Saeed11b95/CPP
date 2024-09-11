#include <iostream>
#include <string>

class Base {

public:
  Base() {
    std::cout << "Base Class Constructor" << std::endl;
    data = new int[20];
  }
  virtual ~Base() { // To tell c++ that if object is created using pointer also
                    // look for derived class destructors.
    delete[] data;
    std::cout << "Base Class Destructor" << std::endl;
  }
  virtual void Print() { std::cout << "Hello There! (Base)" << std::endl; }
  int *data;

private:
  std::string name;
};
class Derived : public Base {
public:
  Derived() {
    data = new int[20];
    std::cout << "Derived class Constructor" << std::endl;
  }
  ~Derived() {
    std::cout << "Derived class Destructor" << std::endl;
    delete[] data;
  }
  void Print() override { std::cout << "Hello There! (Derived)" << std::endl; }
  int *data;
};
int main() {
  //   Derived v;
  /*
  Output:
Base Class Constructor
Derived class Constructor
Derived class Destructor
Base Class Destructor
We can see all the constructors an destructors are called in correct order.
  */

  Base *instance = new Derived;
  /*
  Output:
  ------
  This will only call
  Base Class Constructor
Derived class Constructor
Base Class Destructor
Base class destructor and not the derived so we will leak memory for 20 ints we
allcoated in Derived class. To make it work we have to mark the Base class
destructor as "virtual", this will tell C++ to look for derived class
destructors and call them
  */
  delete instance;
  return 0;
}