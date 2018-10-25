#include <iostream>

int main(){
  // array allocation on the stack
  int array[10] = {0};
  for(int i = 0; i < 10; ++i){ array[i] = i; }
  for(int i = 0; i < 10; ++i){ std::cout << array[i] << std::endl; }
  // break 
  std::cout << std::endl;
  // array allocation on the heap
  int* newArray = new int[10];
  for(int i = 0; i < 10; ++i) { newArray[i] = i; }
  for(int i = 0; i < 10; ++i) { std::cout << newArray[i] << std::endl; }
  delete [] newArray;
  newArray = nullptr;
  // please DO NOT FORGET TO DELETE, memory leak WILL OCCUR
  // set array to NULL to avoid DANGLING POINTER
  return 0;
}
