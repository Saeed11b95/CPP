
#include <iostream>
#include <memory>

class UDT {

public:
  UDT() { std::cout << "UDT object created" << std::endl; }
  ~UDT() { std::cout << "UDT object destroyed" << std::endl; }
};
int main() {

  // Weak pointer
  //-------------
  // Weak pointer is a non-owning pointer, it doesn't increase reference count.
  // https://en.cppreference.com/w/cpp/memory/weak_ptr

  {
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    {

      std::weak_ptr<UDT> ptr2 = ptr1;
      std::cout << "Use count = " << ptr1.use_count()
                << std::endl; // Use count = 2
    }

    std::cout << "Use count = " << ptr1.use_count()
              << std::endl; // Use count = 1
  }
  /*
  Output:
    Use count = 1
    Use count = 1

    We can see that the reference count didnt increase.
    But Why do we need weak_ptr.
    1. Safer way to have dangling pointer
    2. Breaks cycle
    weak_ptr.expired will tell us if the shared_ptr is destroyed or not
  */
  return 0;
}