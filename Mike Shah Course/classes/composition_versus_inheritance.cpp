#include <iostream>
// Inheritence
struct Point2D {
  int x, y;
};
class Character : public Point2D {
public:
  Character() {}
  ~Character() {}
};
// Compostions
struct Point3D {
  int x, y, z;
};
class Character2 {

public:
  Character2(Point2D &r) : ref(r){};
  ~Character2(){};

private:
  Point2D a;
  Point3D b;
  Point2D &ref;
};

int main() {

  // Inheritence is taking one object and extending it. that is having all the
  // features of tha object and more of it's own. On the other hand composition
  // is when we take different object and create a new composed type, e.g struct
  // above ara compositions, so is class Character2 There is yet another type it
  // , sub type of compostion actually it's called "Aggregation". The difference
  // btw aggregation and compsotion is that in aggregation the life time of ref
  // is not tied to object life time, le't take and example

  Point2D my_position;
  Character2 saeed(my_position); // Now here the life time of my_position is not
                                 // tied to saeed, for example let's say
                                 // my_postion was defined in a global scope.
  return 0;
}