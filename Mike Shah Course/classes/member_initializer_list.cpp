#include <iostream>
class Vector3 {

public:
  Vector3() : x(1.0f), y(1.0f), z(1.0f) {
    // Above is member initalizer list, instead of manually assigning values we
    // can use this and according to cpp reference, this is far more efficient
    // we can also do x(1.0f), y(x), z(x){} this will initalize all to 1, but
    // here order matters we cannot do e.g z(1.0f), y(z), x(z) or x(1.0f),
    // z(1.0f), y(z); This will put garbage values in x and y in first case and
    // y in second. The general rule of thumb is to follow initialization order
    // , e.g in our case it is float x,y,z than manual approach x = 0.0f; y =
    // 0.0f; z = 0.0f;
  }
  float x, y, z;
};

std::ostream &operator<<(std::ostream &os, const Vector3 &obj) {
  os << obj.x << "," << obj.y << "," << obj.z << std::endl;
  return os;
}

int main() {
  Vector3 vec1;
  Vector3 result;

  return 0;
}