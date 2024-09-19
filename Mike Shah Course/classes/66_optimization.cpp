#include <iostream>

struct GameState {

  bool checkpoint;
  float score;
  short numberofPlayers;
};

struct GameState2 {

  float score;
  short numberofPlayers;
  bool checkpoint;
};

int main() {
  GameState g;
  std::cout << sizeof(g.checkpoint) << std::endl;      // 1
  std::cout << sizeof(g.score) << std::endl;           // 4
  std::cout << sizeof(g.numberofPlayers) << std::endl; // 2
  std::cout << sizeof(g) << std::endl;                 // 12
  // We can notice our struct is 12bytes which is not equal to 1+2+4 why?
  // THis is because under the hood when computers pass around the objects and
  // vars ,they like to do it in powers of 2, so here it padds 1+3 and then 4
  /* for float and finally 2+2 for short. How to optimize.
1= Lay the vars from biggest to smallest size in structs, like in struct 2
2= use alignof() function on struct to know which number the struct is being
aligned for
Example
====
*/
  GameState2 g2;

  std::cout << alignof(g2) << std::endl;                // 4
  std::cout << sizeof(g2.checkpoint) << std::endl;      // 1
  std::cout << sizeof(g2.score) << std::endl;           // 4
  std::cout << sizeof(g2.numberofPlayers) << std::endl; // 2
  std::cout << sizeof(g2) << std::endl;                 // 8
  // Just by reordering the vars we reduce memory by 33%, Here alignof 4 means
  // the it will try padding according to 4, so we have 4 in float first, the
  // second two are combined 3 so it will add 1 padding, if we add another bool
  // to our Gamestate2 the total will be 8 but struct size won't increase, oit
  // will still remain at 8
  return 0;
}