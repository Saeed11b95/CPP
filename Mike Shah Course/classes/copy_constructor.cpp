#include <iostream>
#include <string>

class Vector {
public:
  float x, y, z;
};
// Heap ALlocated memory example
//===============================
class Array {
public:
  Array() {
    data = new int[10];
    for (int i = 0; i < 10; i++) {
      data[i] = i * i;
    }
  }
  // Copy Constructor
  Array(const Array &rhs) {
    data = new int[10]; // Here we allocate fresh memory for out object and then
                        // copying data one by one into the new data array.
    for (int i = 0; i < 10; i++) {
      data[i] = rhs.data[i];
    }
  }
  ~Array() { delete[] data; }
  void printData() {
    for (int i = 0; i < 10; i++) {
      std::cout << "Element at index " << i << " is: " << data[i] << std::endl;
    }
  }
  void setData(int index, int value) { data[index] = value; }

private:
  int *data;
};
// Stack ALlocated memory example
//===============================
class Array2 {
public:
  Array2() {
    for (int i = 0; i < 10; i++) {
      data[i] = i * i;
    }
  }
  // No need for Copy Constructor because array is stack allocated array.
  ~Array2() {}
  void printData() {
    for (int i = 0; i < 10; i++) {
      std::cout << "Element at index " << i << " is: " << data[i] << std::endl;
    }
  }
  void setData(int index, int value) { data[index] = value; }

private:
  int data[10];
};
int main() {
  Vector myvec;
  myvec.x = 4.2;
  myvec.y = 3.33;
  myvec.z = 2.33;

  Vector anothervec = myvec;
  std::cout << anothervec.x << "," << anothervec.y << "," << anothervec.z
            << std::endl; // 4.2,3.33,2.33
  // We can see that the anothervec gets all the member variables of myvec, This
  // is because all the member variables we have are primitive data types of the
  // default copy constructor will allocate enough memory for members and copy
  // over.
  /*
  By Default:
  ============
  1. C++ provides a copy constructor
  2. C++ provides an destructor
  3. C++ provides Default constructor.
  */
  Vector yetanothervec;
  yetanothervec = myvec; // This is not copy constructor, actually this is
                         // assignmet operator.

  // Let' play with array class
  Array myarray;
  myarray.setData(3, 100);
  myarray.printData(); // Element at index 3 is: 100
  Array myarray2 = myarray;
  myarray2.printData();

  /*
  This copy will work because c++ gives copy constructor, but since we are
  freeing memory in our destructor, we see the below error. free(): double free
  detected in tcache 2

  */
  // Let's do another experiment.
  //   Array myarray3;
  //   Array myarray4 = myarray3;
  //   // Now let's change values;
  //   myarray3.setData(2, 3343434);
  //   myarray3.printData(); // Element at index 2 is: 3343434
  //   myarray4.printData(); // Element at index 2 is: 3343434
  // We saw bothe values got changed, so what is going on?
  /*
  Explaination:
  ============
  Under the hood C++ creates a shallow copy e.g when we do Array
  myarray4=myarray3 C++ will do myarray4.data = myarray3.data. when destructor
  of myarray3 instance is called, it deletes that memory and then later myarray4
  will also try to delete the same memory causing above error. Shallow Copy
  won't work for dynamically allocated memories, so Rule of Thumb:
  ============
  If your code involves dynamic memory allocation, then always write your own
  copy constructor in objects.
  ============
  */
  // COPY Constructor
  //----------------
  Array arr1;
  Array arr2 = arr1;
  arr1.setData(2, 34343);
  arr1.printData(); // Element at index 2 is: 34343
  arr2.printData(); // Element at index 2 is: 9
  // Now we don't face the error of de-allocation of memory twice also the
  // changing values of arr1 won't change values of arr2

  // Statically Allocated Array
  Array2 arr3;
  Array2 arr4 = arr3;
  arr3.setData(2, 34343);
  arr3.printData(); // Element at index 2 is: 34343
  arr4.printData(); // Element at index 2 is: 9
  // We don't need copy constructors for stack arrays.

  return 0;
}