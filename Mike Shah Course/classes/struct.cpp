#include <iostream>

// sturct vs class
//===============
//   Sturct and class are exactly the same except that by default in struct all
//   members are public and by default all members in class are private, unless
//   specifically declared.

struct Vector3 {

  float x, y, z;
};

class Vector {
  float x, y, z;
};

int main() {

  Vector x;  // class
  Vector3 y; // sturct
  // x.x = 0;   // This will raise exception
  /*
  struct.cpp:15:9: note: declared private here
   15 |   float x, y, z;
      |         ^
  */

  y.x = 4;
  return 0;
}