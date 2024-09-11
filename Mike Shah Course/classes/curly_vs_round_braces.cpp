#include <initializer_list>
#include <iostream>
#include <vector>
struct UDT {
  UDT(int a, int b, int c) { std::cout << "constructor with three params \n"; }
  UDT(std::initializer_list<int>
          d) { // we can instead do : data(d), this is more efficient tah nline
               // 8 because it doesn't create any copies.
    std::cout << "initializer_list consturctor \n";
    data = d;
  }
  ~UDT() {}

private:
  std::initializer_list<int> data;
};
int main() {
  // We can initialize three ways. In below example all of them will work.
  //   int a = 4;
  //   int b(4);
  //   int c{4};

  //   int d = 4.2; // This will work
  //   int e(4.2);  // This will also work, it will floor to 4
  //   int f{4.2};  // This will raise exception that the numbers should be int

  // For User Defined Types not primitive types as above
  std::vector<int> v{1, 2, 3}; // For stl containers or User Defined Types {}
                               // this means initializer_list
  for (auto &i : v) {
    std::cout << i << "\n";
  }

  UDT myobj{
      1, 3,
      3}; // since there is a constructor with initailizer_list in our
          // implementation, and since there are curly braces in initialization,
          // it will call tha method and initialize the data.
  UDT another{1, 3, 5}; // If we comment the constructor with initializer_list
                        // then this will call the first constructor.
  // If we instead do
  UDT another2{2.2, 3.3,
               4.4}; // with initializer_list method commented out, it will call
                     // first constructor with ints ans since curly braces, it
                     // will enforce strict types and raise exception;
  UDT another3(
      2.3, 5.5,
      6.5); // This will call first constructor regardless of initializer_list
            // constructor, and will will floor floats to make them ints.
  return 0;
}