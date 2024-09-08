// In general operator overloading is not specific to classes but it goes well
// if studied with classes.

#include <iostream>

class Vector3 {

public:
  Vector3(float x_, float y_, float z_) {
    x = x_;
    y = y_;
    z = z_;
    // Warning never use same names for class members var and input to
    // constructor e.g x=x; will not set values of argument x to member x rather
    // C++ will think that we are assigning class member x to itself. This can
    // cause unexpected behaviour.
  }
  Vector3() {

    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
  }
  // Let's implement this as stream operator
  // This can be defined ouside object so let's see how
  void Print() {
    std::cout << "x:" << x << "\ny:" << y << "\nz:" << z << std::endl;
  }
  Vector3 operator+(const Vector3 &rhs) const {
    Vector3 result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    result.z = z + rhs.z;
    return result;
  }
  // prefix increment/ pre increment operator.
  Vector3 &operator++() {
    x = x + 1;
    y = y + 1;
    z = z + 1;
    return *this;
  }
  // post increment, above is more efficient way to do thing, as it doen't
  // create any copies
  Vector3 operator++(int) {
    Vector3 temp = *this;
    x = x + 1;
    y = y + 1;
    z = z + 1;
    return temp;
  }
  bool operator==(const Vector3 &rhs) const {
    if (x == rhs.x && y == rhs.y && z == rhs.z) {
      return true;
    }
    return false;
  }
  float x, y, z;
};

std::ostream &operator<<(std::ostream &os, const Vector3 &obj) {
  os << obj.x << "," << obj.y << "," << obj.z << std::endl;
  return os;
}

// Operators as functions
//======================
// We can also implement any operator as free function instead of class method.
bool operator==(const Vector3 &lhs, const Vector3 &rhs) {
  if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z) {
    return true;
  }
  return false;
}
int main() {
  Vector3 vec1{3.0f, 2.0f, 1.0f};
  Vector3 vec2{1.0f, 2.0f, 3.0f};
  Vector3 result;
  result =
      vec1 + vec2; // actually this is similar to vec1.plus(vec2) if we had
                   // implemented plus function in class instead of operator +
  result.Print();  // x:4, y:4, z:4
  ++result;
  /*
  The Difference between ++result and result++ in c++ is that ++x increments
  first then returns reference to object on the other hand, x++ returns
  reference to object before increment. so if we are doing it in loop we will
  see ++x in same iteration and x++ in next iteration
  */
  result.Print(); // x:5, y:5, z:5
  // Let's use our custom ostream operator <<
  std::cout << result << std::endl; // 5,5,5
  // == operator
  if (result == result) {
    std::cout << "Equal" << std::endl; // Equal
  }
  return 0;
}