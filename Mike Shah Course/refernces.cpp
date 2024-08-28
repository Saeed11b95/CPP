#include <iostream>
#include <typeinfo>

int
main ()
{
  int x = 43;
  std::cout << "x value: " << x << std::endl;
  std::cout << "x address: " << &x << std::endl;

  // creating a reference here
  int &ref = x;

  std::cout << "ref value: " << x << std::endl;
  std::cout << "ref address: " << &x << std::endl;

  /*
  output :
  x value: 43
    x address: 0x7ffc6e645a6c
    ref value: 43
    ref address: 0x7ffc6e645a6c
  */
  // Note that x and ref has same value and address, so what is going on here/
  // Actually behind the scenes whenever C++ sees ref it replaces with x.
  // What is purpose of this then?
  // We usually use them to pass data to function, we pass data using
  // references. Another reason is that references are safe, we have to
  // initialize them with a value.
  std::cout << "x type : " << typeid (x).name () << std::endl;
  std::cout << "ref type: " << typeid (ref).name () << std::endl;
  /*
  output
        x type : i
        ref type: i
  */
  // using type info we can find out the types and other information of the
  // variables. more on this here
  // https://en.cppreference.com/w/cpp/language/typeid
  // https://en.cppreference.com/w/cpp/types/type_info#:~:text=The%20class%20type_info%20holds%20implementation,is%20neither%20CopyConstructible%20nor%20CopyAssignable.
  return 0;
}