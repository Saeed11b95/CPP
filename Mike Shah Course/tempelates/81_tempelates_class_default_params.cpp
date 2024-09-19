// https://en.cppreference.com/w/cpp/language/class_template
#include <iostream>
// We can put default params in tempelates for classes, as below
template <typename T, size_t Size = 10> //
class Container {
public:
  Container() {
    std::cout << Size << std::endl;
    m_data = new T[Size];
  }
  ~Container() { delete[] m_data; }

private:
  T *m_data;
};

int main() {
  Container<int, 19> x; // 19
  Container<int> u;     // 10
  // This will only work in C++17 and beyond, because the Class tempelate
  // argument deduction was introduced in c++17

  return 0;
}