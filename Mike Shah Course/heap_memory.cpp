#include <iostream>
#include <memory>

int
main ()
{

  int *x = new int; // new keyword allocated memeory on heap
  delete x; // delete frees the memory, if we don't delete explicitly, then
            // this won't be cleared by os and if in loop it happens out
            // computer can crash
  // new allows us to allocate resources at runtime, the resource is returned
  // to us in pointer. Let's see it in action
  int numberofStudents = 0;
  std::cout << "How many students in our class: " << std::endl;
  int *students = new int[numberofStudents];
  for (int i = 0; i < numberofStudents; i++)
    {
      students[i] = i;
    }
  delete[] students;
  // Now we have to delete this memory before we go out of scope or program
  // ends otherwise this memory will be leaked. We can use valgring ./main to
  // see how much memory we are loosing. it tool to debug memory.
  return 0;
}