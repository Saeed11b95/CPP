#include <functional>
#include <iostream>
int add(int x, int y) { return x + y; }
int multiply(int x, int y) { return x * y; }

// We can also define our function pointer using typedef
typedef int (*FPnIntegerOperations)(int, int);
int main() {

  std::cout << "Operation + :" << add(2, 3) << std::endl;     // Operation + :5
  std::cout << "Operaton x :" << multiply(2, 3) << std::endl; // Operaton x :6
  // Now let's define a function pointer
  int (*op)(int, int); // Notice the syntax, return type (pointer name) (arg1
                       // type, arg2 type);
  op = add;
  std::cout << "Operation + :" << op(2, 3) << std::endl;      // Operation + :5
  std::cout << "Operaton x :" << multiply(2, 3) << std::endl; // Operaton x :6

  // now we can customize which function this pointer points to, so we can take
  // use input usin std::cin and ask what operation user want to do and assign
  // function appropriately
  // Using typedef
  FPnIntegerOperations opp;
  opp = add;
  // This is essentailly the same as line 13
  // We can also define function pointer in yet another way using std function,
  // more on this here Defined in header <functional>
  // https://en.cppreference.com/w/cpp/utility/functional/function
  std::function<int(int, int)> oppp; // syntax is <return_type(argx type......)>
  oppp = multiply;
  return 0;
}