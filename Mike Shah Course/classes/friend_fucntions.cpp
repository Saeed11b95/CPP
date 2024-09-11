/*
The friend declaration appears in a class body and grants a function or another
class access to private and protected members of the class where the friend
declaration appears.
*/
#include <iostream>
class Another {
  friend class UDT; // Now this will allow UDT calss to access all the private
                    // memebers fo Another class
};
class UDT {
public:
  UDT() : my_private_var(3) {}
  friend void PrintPrivateVar(UDT instance);

private:
  int my_private_var;
};

void PrintPrivateVar(UDT instance) {

  std::cout << "Private var is: " << instance.my_private_var << std::endl;
}
int main() {
  UDT instance;
  //   std::cout << instance.my_private_var
  //             << std::endl; // This will raise an exception, because
  //                           // my_private_var is private memeber of class
  //                           UDT.
  PrintPrivateVar(instance); // Private var is: 3, so the friend fucntion tells
                             // UDT class that PrintPrivateVar is freind and can
                             // access private members.

  // Most Common use case is operator overloading, e.g define operator as
  // function and the make it friend of class
  return 0;
}