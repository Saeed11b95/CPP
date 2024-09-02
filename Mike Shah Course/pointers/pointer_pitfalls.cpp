#include <iostream>

int main() {
  // ----->>> Pitfall 1
  int *px = nullptr; // 0x0
  *px = 399;
  // If we compile and run this program we will get segmentatation fault.
  // Because we are trying to derefrecne something that we don't have acces to,
  // null ptrs are available in c++ 11 and forward.
  // --->>> Pitfall 2
  int *newarr = new int[1000];
  // We allocate memory for something and don't release it before going out of
  // scope

  // ----->>>> Pitfall 3
  int *x = new int;
  *x = 42;
  delete x;
  delete x;
  // Deleting the memory twice, this might raise an exception where compiler
  // complains double free detected.
  return 0;
}