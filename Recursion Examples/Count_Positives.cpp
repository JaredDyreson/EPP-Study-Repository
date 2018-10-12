#include <iostream>

template <typename T>
size_t isPositive(T value) { return (value > 0) ? 1 : 0; }

template <typename T>
size_t countPositive(T* p, size_t start, size_t end){
  if(start == end) { return isPositive(*p); }
  return (isPositive(*p) + countPositive(p+1, start+1, end));
}
int main() {
  int x[] = { 1, -2, 3, -22, 100 };
  std::cout << countPositive(x, 0, 4) << std::endl;
  return 0;
}
