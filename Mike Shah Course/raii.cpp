#include <iostream>

// RAII (Resource Aquisiton is Initialization):
// Its just a fancy way to say that the resources you aquires should be released
// before your objects is out of scope, e.g in class release resources in
// destructor and release memory if using normal pointers for allocations.
int main() {

  int *collection = new int[10];
  collection[0] = 3;
  collection[2] = 33;
  return 0;
}