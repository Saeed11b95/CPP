// https://en.cppreference.com/w/cpp/language/function_template

#include <iostream>
#include <typeinfo>
template <typename T> T square(T input) { return input * input; }

template <typename T1, typename T2> void foo(T1 input1, T2 input2) {
  std::cout << typeid(input1).name() << std::endl;
  std::cout << typeid(input2).name() << std::endl;
}

template <typename T1, size_t N> void foo2(T1 input1) {
  std::cout << typeid(input1).name() << std::endl;
  std::cout << typeid(N).name() << std::endl;
}
int main() {

  foo<int, float>(4, 3.14); // prints i, f for int and float
  foo2<int, 29>(4);
  // Notice here in foo2 we have explicityly specified type of N as size_t,
  // which is unsigned int, and then we pass number, this is sort of similat to
  // instantiating a array as std::array<int, 20>
  return 0;
}