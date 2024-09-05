#include <iostream>
#include <string>
class Student {
public:
  Student(std::string name, int roll_no);
  Student();
  ~Student();
  void PrintName();
  std::string name;
  int roll_no;
};
