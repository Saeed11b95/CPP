#include <iostream>
#include <memory>

class UDT {
public:
  UDT() { std::cout << "UDT Instance created" << std::endl; }
  ~UDT() { std::cout << "UDT Instance is Destroyed" << std::endl; }
};
int main() {

  int x = 43;
  int *ptr = &x;
  std::cout << "*ptr = " << *ptr << std::endl;

  int *ptr2 = ptr;
  std::cout << "*ptr2 = " << *ptr2 << std::endl;

  /*
  Output:
  --------
    *ptr = 43
    *ptr2 = 43
  */
  // This example shows Raw pointers, the allow sharing. These Raw pointers are
  // very useful but they have their shortcomings, e.g
  int *array = new int[100];
  for (int i = 0; i < 100; i++) {
    array[i] = i;
  }
  int *ptr3 = array;
  // Here if we forget to delete our array pointer
  delete[] array;

  // But the problem is raw pointers are prone to making mistakes so we use
  // smart pointers to elliviate these issues

  //--> Unique Pointer
  //------------------
  std::unique_ptr<UDT> saeed = std::unique_ptr<UDT>(new UDT);
  std::cout << "Here...." << std::endl;
  /*
  Ouput:
        UDT Instance created
        Here....
        UDT Instance is Destroyed
  */
  // As we can see the unique pointer automatically takes care of relaesing the
  // memory, e.g when program runs out of scope e.g retrue 0; then destructor of
  // class is automatically called
  // Let's create an array of this type
  std::unique_ptr<UDT[]> saeedarray = std::unique_ptr<UDT[]>(new UDT[100]);
  // In c++ like when we do int * ptr = new int[100], we can do this with any
  // custom object.
  UDT *ptr33 = new UDT[10];
  // Another clean way to do line 51 is
  std::unique_ptr<UDT[]> abc = std::make_unique<UDT[]>(10);

  // Sumary:
  //-------
  // 1. Unique pointer cannot share, (No copies allowed)
  // 2. We do not have t o delete, it automatically does that when it
  // goes out of scope.
  // 3. We can however tranfer ownership, e.g
  std::unique_ptr<UDT[]> another_owner = std::move(abc);
  return 0;
}