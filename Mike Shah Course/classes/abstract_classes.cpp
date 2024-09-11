/*
C++ doesn't have a directly inplemented abstract classes however we can use
virtual functions to implement the same functionality.
*/
#include <iostream>

class IRenderer {

public:
  virtual void
  Draw() = 0; // This makes it pure virtual function, which is exactly same as
              // python abstract method, derived classes must implement these
  virtual void Update() {}
};

class OpenGL : public IRenderer {
public:
  void Draw() override { std::cout << "OPenGL :: Draw \n"; }
};
class Vukan : public IRenderer {

public:
  void Draw() override { std::cout << "Vulkan :: Draw \n"; }
};

int main() {
  IRenderer *renderer = new OpenGL;
  renderer->Draw(); // OPenGL :: Draw
  renderer->Update();

  /*
  Summary:
  -------
  1. If you want to implement abstract classes or Interfaces, use pure virtual
  fucntions to d that, the way to define is return_type Func(args) = 0;
  2. If this is present in base class, then derived classes must implemet Func.

  */
  return 0;
}