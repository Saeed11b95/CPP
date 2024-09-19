#include <cmath>
#include <iostream>

template <typename T> bool equal(T a, T b) { return (a == b); }
template <> bool equal(float a, float b) { return fabs(a - b) < 0.0000001f; }
int main() {

  std::cout << equal<int>(2, 2) << std::endl; // 1
  std::cout << equal<int>(2, 3) << std::endl; // 0
  std::cout << equal<float>(1.0f - 0.99999999f, 0.00000001f)
            << std::endl; // 0, this zero is becauwe of floting point precision,
                          // to solve this we can write specialzed funtion

  return 0;
}