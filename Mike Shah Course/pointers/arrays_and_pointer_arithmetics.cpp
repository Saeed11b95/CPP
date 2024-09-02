#include <iostream>

int main() {
  // int array[5]; to initalize empty array of 5 elements
  int array[] = {1, 2, 3, 4, 5};
  int *px = array;
  std::cout << array[0] << std::endl;
  std::cout << "px is: " << px << std::endl;
  std::cout << "value at px is: " << *px
            << std::endl; // dereferencing the pointer
  /*
  Ouput:
    1
    px is: 0x7ffd3e42b0c0
    value at px is: 1
  As we can see that the pointer px is pointing to the first element of the
  array, what will happen if we increment our pointer
  */
  px++;
  std::cout << "px is: " << px << std::endl;
  std::cout << "value at px is: " << *px
            << std::endl; // dereferencing the pointer
                          /*
                          Output:
                           px is: 0x7ffe09ba5bf4
                           value at px is: 2
                           We can see that the pointer has incremented to point to the memory address of
                          second elemnt now], Notice that the address has changed by 4bytes because in
                          our computer int is 4 bytes                         to, certainly know the
                          size of any data type in                         any machice we have to run
                          sizeof(int/float/double)                         this will surely tell us                         the
                          size of datatype on current machine because in                         c++ it
                          can vary depending                         on                         the
                          machine.
                          */
  std::cout << *(px + 0) << std::endl;
  std::cout << *(px + 1) << std::endl;
  std::cout << *(px + 2) << std::endl;
  std::cout << *(px + 3) << std::endl;
  std::cout << *(px + 4) << std::endl;
  /*
  Output:
        2,3,4,5,32764

Note: note that at index 4 we got a big value that we didn't initialize, why?
because this is not index 4 we did px++ above so this index is out of bound of
our array. syntax:  *(this means apply arithimetic operation to pointer and then
dereference it.)
  */
  std::cout << *(array + 0) << std::endl;
  std::cout << *(array + 1) << std::endl;
  std::cout << *(array + 2) << std::endl;
  std::cout << *(array + 3) << std::endl;
  std::cout << *(array + 4) << std::endl;
  /*
  Output:
  1,2,3,4,5
  Notice that we can do that same this with out array var, in raw arrays name is
  also a pointer to the first element but it is not the same as normal pointer
  because this array var also stores some extra information Basically array is a
  block of memory, so doing array[0] is similar operation as *(array+0) so []
  are actually incrementing memory and dereference.

  */
  return 0;
}