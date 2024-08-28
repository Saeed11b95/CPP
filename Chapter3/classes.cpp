#include <iostream>
#include <stdio.h>

// These are the concepts from C++ book by Bjarne
// Lets implement simple class to implement Complex number in C++
// This is basically practice to learn more about classes in C++

class Complex
{

  double real, imaginary;

public:
  // :NOTE:
  // This implements the constructors of the class, instead of setting
  // variables to default values like in python Here we define three
  // constructors for three different situations. : real{r}, imaginary{i} {},
  // we initialize btw : and {} might seem strange, it is actually called
  // member initalizer list in C++, it is more efficient way to initialize
  // multiple members of the class.
  Complex (double r, double i) : real{ r }, imaginary{ i } {}
  Complex (double r) : real{ r }, imaginary{ 0 } {}
  Complex () : real{ 0 }, imaginary{ 0 } {}

  // These are set of method that are setters and getters, like if we want to
  // get real part of Complex number similarly another function is overloadedto
  // set the value of real and imaginary numbers
  double
  re () const
  {
    return real;
  }
  double
  imag () const
  {
    return imaginary;
  }
  void
  re (double d)
  {
    real = d;
  }
  void
  imag (double d)
  {
    imaginary = d;
  }

  Complex &
  operator+= (Complex z)
  {
    real += z.real, imaginary += z.imaginary;
    return *this;
  }
  Complex &
  operator-= (Complex z)
  {
    real -= z.real, imaginary -= z.imaginary;
    return *this;
  }
  friend Complex
  operator+ (Complex a, Complex b)
  {
    return a += b;
  }
  friend Complex
  operator- (Complex a, Complex b)
  {
    return a -= b;
  }
};
int
main ()
{
  Complex v (44, 44);
  Complex v2 (55, 55);
  std::cout << v.re () << "\n" << v.imag () << std::endl;
  v += v2;
  std::cout << v.re () << "\n" << v.imag () << std::endl;
  return 0;
};
