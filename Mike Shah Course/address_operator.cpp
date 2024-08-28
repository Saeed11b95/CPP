#include <iostream>

int
foo ()
{
  return 0;
}
int
foo2 ()
{
  return 2;
}
int
main ()
{

  int x = 49;
  float y = 34;
  char a = 'a';
  signed char b = 'b';
  unsigned char c = 'c';
  // & is addres operator in C++ and c, when we do &x it mean address of
  // variable x

  std::cout << "x: " << &x << std::endl;
  std::cout << "y: " << &y << std::endl;
  std::cout << "a: " << &a << std::endl;
  std::cout << "b: " << &b << std::endl;
  std::cout << "c: " << &c << std::endl;
  /*
  Output:
  x: 0x7fffe5782760
  y: 0x7fffe5782764
  a: abc1
  b: bc1
  c: c1
  Notice that for characters it prinds funky stuff, why is that?
  Because these are characters, c++ start interpreting as string.
  to print address we have to cast the strings with (void*) before &var
  */
  std::cout << "x: " << &x << std::endl;
  std::cout << "y: " << &y << std::endl;
  std::cout << "a: " << (void *)&a << std::endl;
  std::cout << "b: " << (void *)&b << std::endl;
  std::cout << "c: " << (void *)&c << std::endl;
  /*
  output:
    x: 0x7ffdfc97f390
    y: 0x7ffdfc97f394
    a: 0x7ffdfc97f38d
    b: 0x7ffdfc97f38e
    c: 0x7ffdfc97f38f
  */
  /*
  functions are also stored somewhere, so we can also print the address of the
  fucntions. but we have to cast the fucntions same as strings to print their
  address
  */
  std::cout << "c: " << &foo << std::endl;
  std::cout << "c: " << (void *)&foo << std::endl;
  std::cout << "c: " << &foo2 << std::endl;
  std::cout << "c: " << (void *)&foo2 << std::endl;
  /*
  Output:
        c: 1
        c: 0x5f051d53a209
        c: 1
        c: 0x5f051d53a218
  */
  return 0;
}