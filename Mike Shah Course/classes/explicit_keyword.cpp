/*
1) Specifies that a constructor or conversion function(since C++11)or deduction
guide(since C++17) is explicit, that is, it cannot be used for implicit
conversions and copy-initialization. 2) The explicit specifier may be used with
a constant expression. The function is explicit if and only if that constant
expression evaluates to true.

*/
#include <iostream>

class UDT {
public:
  explicit UDT(int); // here only the input data type is written not input var

private:
  int my_private_var;
};
UDT::UDT(int i) {
  my_private_var = i;
  std::cout << "m_variable: " << my_private_var << std::endl;
}

int main() {
  UDT my =
      20.2f; // This won't raise an exception if the constructor in simply
             // initialized because the compiler will convert 20.2 to 20 and
             // pass to constructor, somtimes we don't want this behaviur
  UDT my2 = 20.2f; // Now with explicit keyword this program won't compile, this
                   // makes code a bit more safer and these kind of semantic
                   // bugs can be avoided

  // https://en.cppreference.com/w/cpp/language/explicit
  return 0;
}