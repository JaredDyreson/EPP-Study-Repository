#include <iostream>

template <typename T>
bool isEven(T value) { return (value % 2 == 0) ? 1:0 ; }

template <typename T>
size_t countEven(T* p, size_t s, size_t e){
  if(s == e) { return isEven(*p); }
  return (isEven(*p) + countEven(p+1, s+1, e));
}

int main() {
  int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8 };
  std::cout << countEven(x, 0, 7) << std::endl;
  return 0;
}
