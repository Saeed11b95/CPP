#include <iostream>
#include <string>
int get34() { return 34; }
int main() {

  //--> Lvalue: something with a memory location e.g
  int i = 30; // Here left hand side is Lvalue

  // --> Rvalue: on the right side of an assigment expression, e.g in above
  // example 30 is an Rvalue More on value categories here
  // https://en.cppreference.com/w/cpp/language/value_category Now what will
  // happen if
  //   10 = i;
  // Lvalue_Rvalue.cpp:11:6: error: lvalue required as left operand of
  // assignment 11 |      10 = i; |      ^~
  // That means c++ doesn't allow R values to be on left side.
  /*
  Example2:
  ---------
  */
  int a = 1;
  int b = 2;
  int c = (a + b); // Question what are L values and R values.
  // Answer: Here a, b, c are Lvalues. But in expression 3, (a+b) is a Rvalue or
  // more precisely a xvalue(expiring value) becaue under the hood c++ will add
  // Rvalues of a and b and assign the sum to 'c'

  // Example 3:
  int array[200];
  array[10 + a] = 4;
  // Note here the index in array 10+a is a temporary values it doesnt have
  // address where it is stored so it is alos a R value.

  // Example 3:
  //  get34() = 20;
  //  This example will also through above exception, because get34() returns
  //  int which is a Rvalue and we are trying to assign Rvalue into Rvalue.

  // Lvalue Refernce
  //-----------------
  //  funct(int &x, int &y) this is Lvalue reference.
  int x = 20;
  int &y = i;
  // This is valid operation, we are creating a reference to x in y
  // What about this?
  // int &ref = 10;
  /*
  Lvalue_Rvalue.cpp:45:16: error: cannot bind non-const lvalue reference of type
 ‘int&’ to an rvalue of type ‘int’ 45 |     int &ref = 10;
  */
  // So it is not allowed because we are putting Rvalue into var ref, if however
  // we do const int &ref = 20; This is a valid operation

  // Rvalue Reference:
  //------------------
  int &&rvalueref = 10;
  std::cout << &rvalueref << std::endl;
  std::cout << rvalueref << std::endl;
  // OUtput: 0x7fffad441aac, 10
  // But why do we use Rvalue references? The answer is efficiency imagine below
  // example
  std::string str1 = "Saeed Ahmad"; // Remember in C++ strings are always ""
  std::string str2 = "Consider this is million character string";
  std::string str3 = str1 + str2;
  // Here we are first doing operation of concatenation into some temporary
  // memory address then copying that resulting Rvalue into str3 If we isntead
  // do
  std::string &&str4 = str1 + str2;
  // This transfers the owenership of temp str1+str2 directrly into str4 instead
  // of making a new copy, so it is more effiecient

  return 0;
}