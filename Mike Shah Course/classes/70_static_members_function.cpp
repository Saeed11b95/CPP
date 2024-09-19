#include <iostream>

struct API {

  API() {}
  ~API() {}
  const static int VER = 3;
  static int MAJOR; // We cannot initialze them here, C++ only alows const
                    // initalization in here, for the rest we have to init them
                    // outside like line 12.
  static int MINOR;
  int ReturnZero() { return 0; }
  static int GetMajorVersion() { return MAJOR; }
};
// Now we have to  define the to access them
int API::MAJOR = 3;

int main() {

  std::cout << "Major: " << API::MAJOR << "\n"; // Major: 3
  // Note we don't have any class instance, actually the static variables are
  // share among instances, they live on their own.
  std::cout << "Major: " << API::GetMajorVersion() << "\n"; // Major: 3
  // With static functions they also become shared among all class instances,
  // notice this fucntion is not tied to instance rather to class
  // std::cout << "Major: " << API::ReturnZero() << "\n";
  // This won't work, because ReturnZero is instance variable.
  return 0;
}