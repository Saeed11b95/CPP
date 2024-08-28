#include <iostream>

int
main ()
{

  int x = 8;
  int *px = &x; // pointers store addresses
  int *px2 = &x;

  x = 0;
  std::cout << "x stores   : " << x << std::endl;
  std::cout << "x's address: " << &x << std::endl;
  std::cout << "px stores  : " << px << std::endl;
  std::cout << "px stores  : " << *px << std::endl;
  std::cout << "px stores  : " << px2 << std::endl;
  std::cout << "px stores  : " << *px2 << std::endl;

  /*
  Output:
            x stores   : 0
            x's address: 0x7ffc21e85644
            px stores  : 0x7ffc21e85644
            px stores  : 0
            px stores  : 0x7ffc21e85644
            px stores  : 0

  */
  // Derefrencing. It means that we can get the value stored at the address in
  // out pointer.
  // Why we use pointers.
  // 1. share data, multiple ownerships of same data
  // 2. memeory management
  // 3. building datastructures
  return 0;
}