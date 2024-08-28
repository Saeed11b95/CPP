#include <array>
#include <iostream>
#include <numeric>
/*
Raw arrys are built into c++, they are similar to C arrays
*/
int
main ()
{
  // This defines array of integers in c++
  int myarray[200];
  // this is how we can loop over them
  for (int i = 0; i < 200; i++)
    {
      myarray[i] = i;
    }
  /*
  we can also use range based loops
  */
  for (auto element : myarray)
    {
      std::cout << element << std::endl;
    }
  /*
  The array is a container and like all containers in C++ we can create
  iterator on top of them and then we can use those iterators to perform
  differenct actions Here is an example of using it in numeric header this is
  also standard library.
  */
  std::iota (std::begin (myarray), std::end (myarray), 0);
  // above line is same as our for loop above which assigns values in out
  // array. 0 means put zero in zeorth element and +1 from there [0,1,2,3..99]
  std::iota (std::begin (myarray), std::end (myarray),
             10); // this one will start filling from 10. [10,11,12....109]

  // NOTE: The above raw array doesn't put any limits on whether we can access
  // elements out of bounds, meaning in above array what if I do
  myarray[2000] = 3303;
  // well some time this will raise segmentation fault but not alway.

  // std::array, C++ standard library provides array interface which gives us
  // some meaningful methods e.g bound checking etc. To use this we have to
  // include <array> header.

  std::array<int, 200> stdarray;
  // now we can do all the operations on this as raw array and some extra
  // functionality. The docs page for std:;array is
  // https://en.cppreference.com/w/cpp/container/array
  // it provides methos like at to get element at some index with bound
  // checking, frot, to get front element and so on, for more see docs

  return 0;
}