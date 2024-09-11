#include <iostream>

class UDT {

public:
  UDT() {}
  ~UDT() {}
  UDT(const UDT &rhs) {}
  void SetValue(int newValue) { m_vlaue = newValue; }
  void AnotherFunc() {}
  int GetValue() {
    AnotherFunc();
    return m_vlaue;
  }

private:
  int m_vlaue;
};
int main() {

  /*
  We have already seen const keyword for the following.
  1. read-only variables
  2. read only params
  */
  UDT u;
  u.SetValue(299);
  std::cout << u.GetValue() << std::endl;
  /*
  New Use Case
  --------------
  - Making all of the member variables in a member function read only.
  - It means let's say in the Getvalue if we were calling AnotherFunc and this
  function somehow changes the m_value, to prevent this we can mark GetValue as
  const as "int GetValue const (){}" This will not allow any modifications to
  member vars.
  - This is called const correctness.

  */
  return 0;
}