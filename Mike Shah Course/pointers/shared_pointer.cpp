#include <iostream>
#include <memory>

class UDT {

public:
  UDT() { std::cout << "UDT object created" << std::endl; }
  ~UDT() { std::cout << "UDT object destroyed" << std::endl; }
};
int main() {

  {
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    {

      std::shared_ptr<UDT> ptr2 = ptr1;
      std::cout << "Use count = " << ptr1.use_count()
                << std::endl; // Use count = 2
    }
    /*
    Here these ptrs will automatically release memory allocated when all the
    pointer pointing to a particular resource/object will go out of scope Under
    the hood C++ maintains a reference count to a resource. and when reference
    count goes to zero object will be destroyed.

    */
    std::cout << "Use count = " << ptr1.use_count()
              << std::endl; // Use count = 1
  }
  std::cout << "The object should be destroyed before this line" << std::endl;
  // Notice here That the use count decrements as ptr2 runs out of scope.
  // Summary:
  // 1. Shared pointers allow us to share same resource
  // 2. Take care of memory alloc, dealloc automatically
  // 3.keeps reference count for shared_ptrs
  return 0;
}