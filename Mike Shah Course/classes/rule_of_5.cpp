#include <iostream>
#include <string>
#include <vector>

class IntArray {

public:
  // Constructor
  IntArray(std::string name);
  // Destructor
  ~IntArray();
  // Copy Assignemt Operator
  IntArray &operator=(const IntArray &rhs);
  // Copy constructor
  IntArray(const IntArray &rhs);
  // Move constructor policy
  IntArray(IntArray &&source);
  // Move assignment operator
  IntArray &operator=(IntArray &&source);

private:
  std::string m_name;
  int *m_data;
};
// Constructor
IntArray::IntArray(std::string name) : m_name(name), m_data(new int[10]) {
  std::cout << "constructor" << std::endl;
}
// Destructor
IntArray::~IntArray() {
  std::cout << "Destroyed" << std::endl;
  delete[] m_data;
}
// Copy constructor policy
IntArray::IntArray(const IntArray &rhs) {
  m_name = rhs.m_name;
  std::cout << "Object copy constructed from " << rhs.m_name << std::endl;
  m_data = new int[10];
  for (int i = 0; i < 10; i++) {
    m_data[i] = rhs.m_data[i];
  }
}
IntArray &IntArray::operator=(const IntArray &rhs) {
  m_name = rhs.m_name;
  std::cout << "Object copy constructed from " << rhs.m_name << std::endl;
  if (this != &rhs) {
    delete[] m_data; // deleting memory here because this is copy assignemt
                     // operator that mean our object is already created and has
                     // m_data already allocated
    // In copy constructor however the object is not yet created, it is being
    // created and copied at the same time.
    m_data = new int[10];
    for (int i = 0; i < 10; i++) {
      m_data[i] = rhs.m_data[i];
    }
  }
  return *this;
}
// Move constructor
// Basically what it is doing is that it transfers resurces from source to
// target and remove references from source.
IntArray::IntArray(IntArray &&source) {
  m_name = source.m_name;
  source.m_name = "";
  m_data = source.m_data;
  source.m_data = nullptr;
  std::cout << m_name << "was move constructed" << std::endl;
}
// Move assignmet operator
IntArray &IntArray::operator=(IntArray &&source) {
  if (this != &source) {
    m_name = source.m_name;
    source.m_name = "";
    m_data = source.m_data;
    source.m_data = nullptr;
    std::cout << m_name << "was move assigned" << std::endl;
  }
  return *this;
}
int main() {

  std::vector<IntArray> myarrays;
  for (int i = 0; i < 10; i++) {
    IntArray temp(std::to_string(i));
    myarrays.push_back(temp);
  }
  /*
     Doing the above will create objects in temp the pass by value e.g create
     copy and put into vectors, if we run our compiled program using valgrind
     ./main Output : total heap usage: 42 allocs, 42 frees, 77,392 bytes
     allocated. Now here because we haven't specified vector size so some extra
     copies as well but the point is accross.
     */
  std::vector<IntArray> myarrays2;
  myarrays2.reserve(10);
  for (int i = 0; i < 10; i++) {
    IntArray temp(std::to_string(i));
    myarrays2.push_back(temp);
  }
  // total heap usage: 23 allocs, 23 frees, 75,952 bytes allocated
  std::vector<IntArray> myarrays3;
  myarrays3.reserve(10);
  for (int i = 0; i < 10; i++) {
    IntArray temp(std::to_string(i));
    myarrays3.push_back(std::move(temp));
  } // total heap usage: 13 allocs, 13 frees, 75,552 bytes allocated

  /*
  Summary:
  ==========
  So the summary of rule of 5 is to implement all 5 of constructors above and
assignment operator, Why?
  -----
  - As we can see this is efficient, 4x efficiency over just plain vec init and
push_back.
  - C++ doesn't provide move constructor implementation by default.
  - Defining move and copy policy makes code more readable and less error prone

  K*/
  return 0;
}