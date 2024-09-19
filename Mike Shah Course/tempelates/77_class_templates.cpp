// https://en.cppreference.com/w/cpp/language/class_template
#include <iostream>

template <typename T> class Container {
public:
  Container(int N) { m_data = new T[N]; }
  ~Container() { delete[] m_data; }

private:
  T *m_data;
};

template <typename T, size_t Size> class Container2 {
public:
  Container2() {
    m_data = new T[Size];
  } // we can directly initialize from tempelate param
  ~Container2() { delete[] m_data; }

private:
  T *m_data;
};

int main() {

  Container<int> c{10}; // In classes we have to do container<int> because they
                        // cannot implicitly deduce datatype of args like
                        // fuctions, e.g here arg to our constructr will always
                        // be int but the array in calss can be any type
  Container<float> c2(20);

  Container2<int, 19> x;

  return 0;
}