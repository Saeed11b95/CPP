#include <iostream>
#include <string>
/*
Class:
--------
A class is a user defined type unlike premitive or built in types like
 int ,float, char, bool etc.
Example:
-------
    Vector, and other std data structures are created using classes.

*/
class Student {
public: // We have to define public APIs/ interfaces under public
        // WaYS TO INITIALIZE CLASS OBJECT.
  // Way 1.
  //-------
  Student(std::string n, int r_no) {
    name = n;
    roll_no = r_no;
  }
  // Way2
  //------
  Student(std::string name, int roll_no) : name(name), roll_no(roll_no) {
    std::cout << "Constructor" << std::endl;
  } // This is called member initalizer list way constructing a class instance.
  // Way3
  //-----
  Student(std::string n, int r) {
    this->name = n;
    this->roll_no = r;
    // This is normal constructor which assign values to member vars of class
  };
  Student() : name(""), roll_no(0) {}
  ~Student() {}
  void PrintName() { std::cout << name << std::endl; }

private: // By default in C++ everything is private.
  std::string name;
  int roll_no;
};

int main() {
  /*
### The Difference btw () initializations and {} initalizations ###
Direct Initialization (()):
------------------------
Uses parentheses.
May allow narrowing conversions (e.g., int x(3.14); truncates to 3).
Can sometimes lead to ambiguities (e.g., "most vexing parse" problem).

Uniform Initialization ({}):
-----------------------------
Uses braces.
Prevents narrowing conversions (e.g., int x{3.14}; causes a compile-time error).
Avoids ambiguities and is preferred in modern C++ (C++11 onwards).
Below are the examples, bot will work.

  */
  Student saeed("saeed",
                4); // here even if we pass 4.5 it will work, it will
                    // automatically convert to 4, i.e cast to int, which
                    // sometimes can produce unexpected behaviour.
  Student waheed{"waheed", 5}; // here 4.5 will create compiler error.
  // We can also create object on heap
  Student *another = new Student{"saeed", 8};
  saeed.PrintName();
  delete another;

  return 0;
}