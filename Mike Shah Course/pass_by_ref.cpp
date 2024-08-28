#include <iostream>

void
PassbyValue (int arg)
{
  arg = 9999;
}
void
PassByRef (int &arg)
{
  arg = 9999;
  std::cout << "x's inside the function is: " << &arg << std::endl;
}

int
main ()
{
  int x = 43;
  std::cout << "x's value is: " << x << std::endl;
  std::cout << "x's address is: " << &x << std::endl;

  // Now let's set value here
  PassbyValue (x);

  std::cout << "x's value is: " << x << std::endl;
  std::cout << "x's address is: " << &x << std::endl;
  /*
  The outputs here will be:
        x's value is: 43
        x's address is: 0x7ffd27c7c0f4
        x's value is: 43
        x's address is: 0x7ffd27c7c0f4
  */
  // Now let's pass by reference
  PassByRef (x);
  std::cout << "x's value is: " << x << std::endl;

  /*
  output:
        x's value is: 43
        x's address is: 0x7ffc63f003a4
        x's value is: 43
        x's address is: 0x7ffc63f003a4
        x's inside the function is: 0x7ffc63f003a4
        x's value is: 9999
  */
  // Notice that the value of x is now changed

  /* By Why use pass by reference?
  1. Mutation, If we want to implement inplace operations then we need this
  2. It is efficient. E.g if we pass around array of million elements, pass by value will first create copy of million and then pass
  
  */
  return 0;
}