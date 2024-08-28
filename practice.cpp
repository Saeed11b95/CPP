#include <iostream>

int
main ()
{
  int array[200];
  for (auto a : array)
    {
      std::cout << a << std::endl;
    }
  return 0;
}
