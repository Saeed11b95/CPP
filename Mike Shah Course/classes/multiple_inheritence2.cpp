#include <iostream>

struct Entity {
  int x{4}, y{5};
};

struct Warrior : public Entity {

  int power{10};
};
struct Goblin : public Entity {
  int power{2};
};
struct Player : public Goblin, public Warrior {};

// with virtaul inheritence
struct Entity1 {
  int x{4}, y{5};
};
// What this virtual does it that here if any class below inherits both of these
// classes it will make sure to take only one copy of member vars.
struct Warrior1 : virtual public Entity {

  int power{10};
};
struct Goblin1 : virtual public Entity {
  int power{2};
};
struct Player1 : public Goblin1, public Warrior1 {};

int main() {

  Player mike;
  //   std::cout << mike.x << std::endl; This is won't work because the instance
  //   mike inherits from warroir and Goblin, so it doesn't know which path to
  //   take upto Entity to get x and y std::cout << mike.y << std::endl;
  // TO get to x and y we have to remove this abiguity

  std::cout << mike.Warrior::x << std::endl; // 4
  std::cout << mike.Warrior::y << std::endl; // 5

  std::cout << mike.Goblin::x << std::endl; // 4
  std::cout << mike.Goblin::y << std::endl; // 5

  /*
  To mitigate this kind of ambiguity in our multiple inheritences, we can use
  keyword "virtual"
  */
  Player1 saeed;
  std::cout << saeed.x << std::endl; // 4
  std::cout << saeed.y << std::endl; // 5 Now it works fine, no ambiguity
  // Finally
  std::cout << saeed.power << std::endl;
  std::cout << saeed.power << std::endl;
  // This won't work and virtual also won't merge this because these are
  // different object but have same member var power so we have to manually
  // resolve it by "saeed.Warrior::power"
  return 0;
}