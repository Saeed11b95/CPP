/*
A lot of the times in C++ we provide class APIs in header file and class
inplementations in cpp files, So headers i APIs that are exposed to end users
and sometimes we don't want the use to be able to look at out private member
vars etc. Therefore to abstract those we create pointer to new object in our
header file and in cpp file we can define those mebmers as mebers of this
initialized object in header, let's see.
*/
#include <iostream>
#include <memory>
#include <string>
class Person {
public:
  Person(std::string n_);
  ~Person();
  std::string GetAttrs();

  /*
  here we could have our meber functions like
  private:
      std::string name;
      std:: string strength;
      std::string speed;
  but doing it like this will expose our memebr vars to end user. so instread
  */
private:
  struct PointerToImplementation;
  PointerToImplementation *newptr;
  // Now we can define all our member vars ar memer fo
  // PointerToImplementation class and put them in cpp file,
  // hiddedn away from end user.
  // We can also define smart pointers then we don't need to destroy int
  // destructor
  // std::unique_ptr<PointerToImplementation> newptr
};

struct Person::PointerToImplementation {
  std::string name;
  std::string speed;
  std::string strength;
  // So we provide implementation of our member pointer class, whic lives in our
  // person class scope.
  // Performace wise this will be slower but it's a trade off one has to make.
};
Person::Person(std::string n) {
  newptr = new PointerToImplementation;
  // Unique ponter implementation will be similar except
  //   newptr = std::make_unique<PointerToImplementation>();
  newptr->name = n;
  newptr->strength = "NA";
  newptr->speed = "NA";
}
Person::~Person() { delete newptr; }
std::string Person::GetAttrs() {
  return newptr->name + ", " + newptr->speed + ", " + newptr->strength;
}

int main() {

  Person newperson{"saeed"};
  Person another("Waheed");
  std::cout << newperson.GetAttrs() << std::endl; // saeed, NA, NA
  std::cout << another.GetAttrs() << std::endl;   // Waheed, NA, NA
  // In summary it's technique to hide away attributes that we don't want user
  // to see.

  return 0;
}