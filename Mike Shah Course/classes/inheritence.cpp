#include <iostream>

class Dog {
public:
  Dog() {}
  void Bark() { std::cout << "bark.." << std::endl; }

  void Walk() {
    x++;
    y++;
  }

private:
  int x, y;
};
class Golden : public Dog {
public:
  Golden() { sticks_retrieved = 0; }
  void Retrieve() {
    std::cout << "Retrieving...." << std::endl;
    sticks_retrieved += 1;
  }
  int sticks_retrieved;
};
class Husky : public Dog {};
int main() {
  Golden dog1;
  dog1.Bark();
  Husky dog2;
  dog2.Bark();

  return 0;
}