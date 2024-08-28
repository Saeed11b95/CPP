#include <iostream>

int
main ()
{

  int x = 3;
  int *px = &x;
  // what if we derefernnce px and change value, what will happen to x
  *px = 444;
  std::cout << "x stores: " << x << std::endl; // x stores: 444
  return 0;
}