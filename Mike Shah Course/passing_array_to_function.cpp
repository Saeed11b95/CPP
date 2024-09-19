#include <array>
#include <iostream>

void PrintArray(int arr[]) {
  // There is no way is C++ to calculate the size of array inside a function
  // where the array is passed as an argument. Here int arr[] is exactly the
  // same as int *arr so to know the size of an array we have to pass it to the
  // function
  std::cout << "sizeof(arr): " << sizeof(arr) << std::endl;
}
void PrintArray(int arr[], size_t size) {
  // here we can pass size as int or size_t, whic is unsigned int datatype in
  // c/c++
  std::cout << "sizeof(arr): " << size << std::endl;
  for (size_t i = 0; i < size; i++) {
    std::cout << "The element at index i is: " << arr[i] << std::endl;
  }
}
int main() {

  int myarray[] = {1, 2, 3, 4, 5};
  PrintArray(myarray); // first fuction above
  // Output : sizeof(arr): 8
  /*
  passing_array_to_function.cpp:4:40: warning: ‘sizeof’ on array function
  parameter ‘arr’ will return size of ‘int*’ [-Wsizeof-array-argument] 4 |
  std::cout << "sizeof(arr)" << sizeof(arr) << std::endl; We get the above
  output, and this warning, It tells us that we are passing a pointer to
  the first element so sizeof will return size of pointer to int.
  */
  int size_of_array = sizeof(myarray) / sizeof(int);
  PrintArray(myarray, size_of_array);
  /*
  Output:
        sizeof(arr): 5
        The element at index i is: 1
        The element at index i is: 2
        The element at index i is: 3
        The element at index i is: 4
        The element at index i is: 5
  */
  // TIP: if we have to pass the container data structure around, we should use
  // vectors because then we won't have to worry abount those size issues, The
  // std library data structures create these abstractions on top of raw array,
  // so passing std::array instead of array[] to function is better because the
  // std::array APIs provide .size() to get size and std::array when
  // myfunc(miarray) passes the array object instance instead of the pointer

  std::array<int, 10> miarray = {2, 3, 3, 3, 5};
  std::cout << miarray.size() << std::endl; // Ouputs: 10

  // FInal Tip: any container data structure passed around to functions, if
  // possible void printArray(vector<int> &arr) pass references to fucntion to
  // aviod copy overhed and also if you don't want to allow the passed container
  // to be modified, then void printArray(const vector<int> &arr) should be
  // passed as const.
  return 0;
}