// https://en.cppreference.com/w/cpp/language/class_template
#include <iostream>

template <typename T, size_t Size> class Container2 {
public:
  Container2() {
    m_data = new T[Size];
  } // we can directly initialize from tempelate param
  ~Container2() { delete[] m_data; }
  static T m_var;

private:
  T *m_data;
};

// We also have to template the static members for instantition,
template <typename T, size_t Size>
T Container2<T, Size>::m_var; // This way we first have to declare it, e.g
                              // template it for the compiler to recognize and
                              // then for each template we can initialize.

int main() {
  Container2<int, 19> x;
  Container2<int, 19> x2;
  Container2<int, 19>::m_var =
      10; // This will be share among all intances instantiated with <int, 19>
  std::cout << Container2<int, 19>::m_var << std::endl; // 10
  Container2<int, 25> x3;
  std::cout << Container2<int, 25>::m_var
            << std::endl; // 0 This prints zero because we haven't instantiated
                          // for <int, 25> out member var

  Container2<float, 4> u;

  return 0;
}