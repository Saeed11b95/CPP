#include <iostream>

class Base {

public:
  Base() { std::cout << "Base Class Constructor" << std::endl; }
  ~Base() { std::cout << "Base Class Destructor" << std::endl; }

public:
  int public_base_var;

private:
  int private_base_var;

protected:
  int protected_base_var;
};
class Derived : public Base {
public:
  Derived() {
    std::cout << "Derived class Constructor" << std::endl;
    public_base_var = 1111;
    protected_base_var = 2333; // Protected vars can be accessed in inherited
                               // classes but not outside
    // private_base_var = 343434; // This won't work because private members are
    // not accessible outside the class
  }
  ~Derived() { std::cout << "Derived class Destructor" << std::endl; }
};
int main() {
  Derived v;
  v.public_base_var = 1111;
  // v.protected_base_var = 2333; This won't work,
  // v.private_base_var = 343434; private members are only accessible to class
  // insed definintion

  /*
  If we do do inherit using this class Derived: protected Base, this will change
  the behaviuor, e.g we won't be able to access anything of Base outside class,
  like on instances of Derived, and inside Derived , public becomed protected.
  */
  return 0;
}