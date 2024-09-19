#include <iostream>
#include <string>
#include <utility>

int main() {

  std::string mystring1 = "copy construct me";
  std::string mystring2;
  std::cout << "mystring1" << mystring1 << std::endl;
  std::cout << "mystring2" << mystring2 << std::endl;
  // Now if we want to assign the mystring1 to mystring2 we can do
  mystring2 =
      mystring1; // This will invoke copy constructor under the hood, and if
                 // string is billion characters long it might take very long or
                 // may even crash our program if done in loops etc.

  mystring2 =
      std::move(mystring1); // This operation will not do copy it will transfer
                            // the ownershipt mystring1 to mystring2
  // The move operation can also be equivilently done as
  mystring2 = static_cast<std::string &&>(mystring1);
  // This essentially is doing static cast on Rvalue and then using
  // "=" which is move assignment operator in this case and not copy assignement
  // operator to assign the value.

  return 0;
}