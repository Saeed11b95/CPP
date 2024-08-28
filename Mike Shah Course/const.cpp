#include <iostream>
// We can use this header to check the types of variables etc
#include <algorithm>
#include <type_traits>
#include <vector>
void
PassByRef (const std::vector<int> &arg)
{
  // Now it will not allow to modify the values of passed vector arg.
}
int
main ()
{

  const int x = 40;
  std::cout << "x : " << x << std::endl;
  std::cout << std::is_const_v<int> << std::endl;
  std::cout << std::is_const_v<const int> << std::endl;

  std::cout << std::is_const<decltype (x)>::value << std::endl;
  /*
  decltype: returns type declared. part of type_traits header.
  Output:
          x : 40
          0
          1
          1
  It mean that int is not const type but "const int" is and the x is also cont
  */
  std::vector<int> myvec (100);
  std::fill (std::begin (myvec), std::end (myvec), 2);
  PassByRef (myvec);
  // This is even more efficent tha vanilla pass by refernce.
  // So there are two primary use cases for const.
  // Not allow data mutation.
  /// efficiency.

  return 0;
}