#include <algorithm>
#include <iostream>
#include <vector>

void
PassbyValue (std::vector<int> arg)
{
  arg[0] = 100;
}
void
PassByRef (std::vector<int> &arg)
{
  arg[1] = 9999;
}

int
main ()
{
  std::vector<int> myvec (
      1000000000); //()are used to initialize number of elements in vec, {} is
                   // use to initialize vec itself with some values e.g
  // type myvec {2,3,4};
  std::fill (std::begin (myvec), std::end (myvec), 1);
  PassByRef (myvec);
  //   PassbyValue (myvec);
  std::cout << "The first element after operation is: " << myvec[0]
            << std::endl;
  std::cout << "The second element after operation is: " << myvec[1]
            << std::endl;

  /* IF we run our program and time it
PassbyValue : 4.14s user 1.81s system 99% cpu 5.953 total
PassbyRef : 3.73s user 0.90s system 99% cpu 4.635 total
So we can clearly see that pass my reference is more efficient.

    */
  return 0;
}