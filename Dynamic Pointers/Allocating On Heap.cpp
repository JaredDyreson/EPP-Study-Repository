#include <iostream>

int main() {
  int* heapInt  = new int;
  heapInt = 0;
  std::cout << heapInt << std::endl;
  delete heapInt;
  heapInt = nullptr;
  return 0;
}
