// https://en.cppreference.com/w/cpp/utility/variadic

#include <iostream>

template <typename T> T Sum(T arg) { return arg; }
template <typename T, typename... Args> T Sum(T arg, Args... args) {
  return arg + Sum(args...);
}
int main() {
  std::cout << Sum(1) << std::endl;
  // But we cannot call this Sum function with more than one argument. Let's
  // modify it
  std::cout << Sum(1, 2, 3, 4, 5) << std::endl; // 15, Now it works

  return 0;
}