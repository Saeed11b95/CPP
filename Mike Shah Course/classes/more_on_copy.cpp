#include <iostream>
#include <vector>

// Heap ALlocated memory example
//===============================
class Array {
public:
  Array() {} // Default constructor
  Array(int size) {
    vec_size = size;
    for (int i = 0; i < vec_size; i++) {
      data.push_back(i * i);
    }
  }
  // Here in copy constructor when we are copying, we make sure to copy all the
  // data memebers
  Array(const Array &rhs) {
    std::cout << "Copy  constructor" << std::endl;
    this->vec_size = rhs.vec_size;
    for (int i = 0; i < rhs.vec_size; i++) {
      data.push_back(rhs.data[i]);
    }
  }
  ~Array() {} // since its stl container vector, it will automatically delete.
  Array &operator=(const Array &rhs) {
    std::cout << "Copy assignment operator" << std::endl;
    if (&rhs == this) {
      return *this;
    }
    // delete the data alread in object
    data.clear();
    this->vec_size = rhs.vec_size;
    for (int i = 0; i < vec_size; i++) {
      data.push_back(rhs.data[i]);
    }
    return *this;
  }
  void printAt(int index) const { std::cout << data[index] << std::endl; }

  void printData() {
    for (int i = 0; i < vec_size; i++) {
      std::cout << "Element at index " << i << " is: " << data[i] << std::endl;
    }
  }
  void setData(int index, int value) { data[index] = value; }

private:
  std::vector<int> data;
  int vec_size;
};

void printArrayAtconst(const Array &a, int index) {
  /*
  Note:
  ====
  notice here that we are passing Array as const reference, Now if a object is
const then the member function being called on this object instace should also
be const. Therefore  void printAt(int index) { std::cout << data[index] <<
std::endl; } member of Array won't work Exception:
  =========
  more_on_copy.cpp:51:62: error: passing ‘const Array’ as ‘this’ argument
discards qualifiers [-fpermissive] 51 | void printArrayAtconst(const Array &a,
int index) { a.printAt(index); } | ~~~~~~~~~^~~~~~~ more_on_copy.cpp:38:8: note:
in call to ‘void Array::printAt(int)’ 38 |   void printAt(int index) { std::cout
<< data[index] << std::endl; } |        ^~~~~~~

Solution:
=========
void printAt(int index) const { std::cout << data[index] << std::endl; }
This const fuction can be called on const as well as non const object instances.
*/
  a.printAt(index);
}
void printArrayAt(Array a, int index) { a.printAt(index); }
int main() {
  Array myarray{1000};
  myarray.setData(0, 999999);
  // Copy constructor
  Array another = myarray;
  another.printAt(0); // 999999
  myarray.printAt(0); // 999999
  // Copy Assignemt operator
  Array myarray2{20};
  Array another2;
  myarray2.setData(0, 1406);
  another2 = myarray2;
  myarray2.printAt(0); // 1406
  another2.printAt(0); // 1406

  // Now let's see how the copy semantics work when we pass the values to
  // functions. e.g
  printArrayAt(myarray, 0);
  /* Output
   Copy  constructor
  999999
  Every time we pass a value to function by value e.g line 69, then C++ creates
  copy of object, which is temp, and passes to function, that's why we see copy
  constructor being called.
  Now this can be extremely problematic if we had 1 million elements in array
  and we run a loop to print each one of them using line 69, then this will
  create copies of my array million time, each time to print one single value
  =============
  How do we Avoid?
  =============
  Pass by reference, don't use copy constructors.
  */
  printArrayAtconst(myarray, 0); // 999999, No copy constructor invoked
  return 0;

  /*
  Tips:
  -----
  1. Pass values by referecne to avoid copies.
  2. Put copy constructor under private: in class, this won't allow accidental
  pass by values for huge objects.
  3. Array(Array &a)=delete{....} This will delete constructor and won't allow
  accidental usage.
  */
}