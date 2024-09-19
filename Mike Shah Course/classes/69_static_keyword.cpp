#include <iostream>
// Static keyword allows us to define persistent vars e.g
void foo() {
  int x = 0;
  x += 1;
  std::cout << x << std::endl;
}
void foo2() {
  static int x = 0;
  x += 1;
  std::cout << x << std::endl;
}
int main() {

  int x = 0; // This is stack memory and it lives in scope. Auto released when
             // out of scope
  int *p =
      new int; // p is a local variable allocate on the heap and heap
               // memory stays until we release it, this also lives in scope, if
               // we don't explicitly delete and out of scope we loose reference
               // to that memory, that memory is leakes os cannot claim it back.
  // Static
  //----------
  for (int i = 0; i < 10; i++) {
    foo();
  } // 1,1,1,......1 it will print 1 10 times
  for (int i = 0; i < 10; i++) {
    foo2();
  } // 1,2,3,..,10 it will print 1-10 because the since int x is static in
    // foo2() scope,it will be only initialized once anthe it persisits. it is
    // persistent there now, however it cannot be used ouside of foo2() scope.
  delete p;
}