#include <iostream>

void
setvalue (int arg)
{
  std::cout << "x's value inside the function before assignment is: " << arg
            << std::endl;
  std::cout << "x's address inside the function is: " << &arg << std::endl;
  arg = 9999;
  std::cout << "x's value inside the function after assignment is: " << arg
            << std::endl;
}

int
main ()
{
  int x = 43;
  std::cout << "x's value is: " << x << std::endl;
  std::cout << "x's address is: " << &x << std::endl;

  // Now let's set value here
  setvalue (x);

  std::cout << "x's value is: " << x << std::endl;
  std::cout << "x's address is: " << &x << std::endl;
  /*
  The outputs here will be:
        x's value is: 43
        x's address is: 0x7ffd27c7c0f4
        x's value inside the function before assignment is: 43
        x's address inside the function is: 0x7ffd27c7c0dc
        x's value inside the function after assignment is: 9999
        x's value is: 43
        x's address is: 0x7ffd27c7c0f4
  */
  // the value has not been modified, Notice that the address insise the
  // function and outside are different that means the C++ is creating acopy of
  // x and passing that copy to the fucntion. This is pass by value, c++
  // created copy of value of x and passed it.
  return 0;
}