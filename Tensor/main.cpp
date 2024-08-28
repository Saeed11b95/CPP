#include <iostream>
#include <range/v3/all.hpp>
#include <string>
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
