#include <iostream>

// this keyword is a pointer to current instance of the object.

class Person {

public:
  Person(int age) { // remeber we saw params name and member var name should not
                    // be same
    // age = age; this won't work
    this->age = age;
  }
  int GetAge() { return age; }
  Person *getTheAddress() { return this; }

private:
  int age;
};

int main() {
  Person saeed(32);
  std::cout << saeed.GetAge() << std::endl;        // 32
  std::cout << saeed.getTheAddress() << std::endl; // 0x7fffc1d66434
  std::cout << &saeed << std::endl;                // 0x7fffc1d66434
  Person *Rashid = new Person(40);
  std::cout << Rashid->getTheAddress() << std::endl; // 0x5a5fb3f2a6c0
  std::cout << &Rashid << std::endl;                 // 0x7ffe4a4ec530
  std::cout << Rashid << std::endl;                  // 0x5a5fb3f2a6c0
  // Notice here the address of pointer Rashid and the address of object
  // instance is the same. But when we derefrence the Rashid pointer, it indeed
  // return the address of instance.
  return 0;
}