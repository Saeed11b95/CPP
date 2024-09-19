#include <iostream>

template <typename T, typename T2> auto Multiply(T a, T2 b) {
  // This is a way to make functions more flexible, we can set return type to
  // auto and let the compiler figure out the correct return type
  return a * b;
}

int main() {

  std::cout << Multiply<float, int>(3.3f, 2) << std::endl;
  return 0;
}