#include "default_constructor_destructor.h"
#include <iostream>
#include <string>

Student::Student() {

  name = "No Name";
  roll_no = 0;
  std::cout << "Constructor" << std::endl;
}
Student::Student(std::string n, int r) {
  name = n;
  roll_no = r;
}
Student::~Student() { std::cout << "Destructor: " << std::endl; }
void Student::PrintName() {
  std::cout << "The name of Student is: " << name << std::endl;
}

int main() {

  Student saeed; // By default c++ provides an empty constructor like Student(),
                 // that is why we are able to create instance without having
                 // defined constructor. Destructor is also provided by default.
  saeed.name = "saeed";
  saeed.roll_no = 4;
  saeed.PrintName();
  // Since we have defined multiple costructors, e.g we use constructor without
  // argument above now, let's use constructor with arguments
  Student waheed("waheed", 4);
  waheed.PrintName();
  /*
Output:
------
      Constructor
      The name of Student is: saeed
      The name of Student is: waheed
      Destructor:
      Destructor:
*/
  return 0;
}