#include <iostream>

template <typename T> T square(T number) { return number * number; }

int main() {
  std::cout << square(4) << std::endl;    // 16
  std::cout << square(4.2) << std::endl;  // 17.64
  std::cout << square(4.5f) << std::endl; // 20.25
  // Notice we called the same function with three difference agruments, int,
  // double and float. Tempelates are the way to not write fucntions for each
  // type and rather delegate that work for compiler, under the hood, compiler
  // is actually generating the proper versions of sqaure funtions   and calling
  // them.

  std::cout << square<int>(4) << std::endl;      // 16
  std::cout << square<double>(4.2) << std::endl; // 17.64
  std::cout << square<float>(4.5f) << std::endl; // 20.25
  // We can also explicitly tell the compiler our types but this is not required
  // in c++20 and beyond
  return 0;
}