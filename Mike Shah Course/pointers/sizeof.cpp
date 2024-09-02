#include <iostream>
#include <vector>
int main() {
  // Local variable primitive type
  int x = 7;
  // A pointer
  int *px = &x;
  // A Stack allocated array
  int array[] = {1, 2, 3, 4, 5};
  // A Heap allocated array
  int *dynamicallyallocatedArray = new int[1000];
  std::vector<int> vec;
  vec.push_back(4);
  vec.push_back(55);
  vec.push_back(4);
  std::cout << "x                         : " << sizeof(x) << std::endl;
  std::cout << "px                        : " << sizeof(px) << std::endl;
  std::cout << "array                     : " << sizeof(array) << std::endl;
  std::cout << "dynamicallyallocatedarray : "
            << sizeof(dynamicallyallocatedArray) << std::endl;
  std::cout << "vector                    : " << sizeof(vec) << std::endl;

  /*
  Output:
        x                         : 4
        px                        : 8
        array                     : 20
        dynamicallyallocatedarray : 8
        vector                    : 24
 Notice that int is 4 bytes and pointer is 8 bytes becasue we have 64bit system.
 --> Stack array: is 20 because we have 5 elements and 4x5=20, This works for
 stack array, because compiler has access to the stack memory and it knows
 exactly
 --> Heap Array: what is going on. Now what's going on with heap array?
    -- For the dynamically allocated array because it is just a pointer to the
 first element thus the size is 8 which is standard on 64bit machine.
 --> vector:
     --for vectory when we call sizeof on it, it returns the size of vectory
 data structure or in other words size of vector class instance that we created,
        So it Does not matter if we create vector of 20000 elements the output
 of sizeof(vec) will always be 24 To get number of elements in vector we will
 have to do vec.size()

  */

  return 0;
}