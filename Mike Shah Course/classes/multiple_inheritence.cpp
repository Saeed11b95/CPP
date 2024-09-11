#include <iostream>
struct noncopyable {
  noncopyable() = default;
  noncopyable(const noncopyable &rhs) = delete;
  noncopyable &operator=(const noncopyable &rhs) = delete;
};
struct Dog {
  void Bark() { std::cout << "Dog::Bark\n"; }
};
struct Golden : public Dog {
  void Bark() { std::cout << "Golden::Bark\n"; }
};
struct BorderCollie : public Dog {
  void Bark() { std::cout << "BorderCollie::Bark\n"; }
};
struct Coltriever : public Golden, BorderCollie {
  void Bark() { std::cout << "Coltriever::Bark\n"; }
};

int main() {

  Dog dog;
  Golden golden;
  BorderCollie bordercollie;
  Coltriever colt;

  dog.Bark();
  golden.Bark();
  bordercollie.Bark();
  colt.Bark();
  /*
    Dog::Bark
    Golden::Bark
    BorderCollie::Bark
    Coltriever::Bark
  */
  Dog *dog1 = new Dog;
  Dog *golden1 = new Golden;
  Dog *bordercollie1 = new BorderCollie;
  Dog *colt1 = new Coltriever; // This confuses the compiler, It doesn't know
                               // which path to take from conversion from colt
                               // to do, i.e Golden or bordercollie
                               /*
                               Usually, Multiple inheritences are not very common and not required,.
                               However there are some use cases where the can be used.
                               1. If we inherit any class from noncopyable and anyother class, it won't allow
                               copying.
                               */
  return 0;
}