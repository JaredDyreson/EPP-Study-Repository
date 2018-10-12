#include <iostream>

template <typename T>
bool isZero(T value) { return (value == 0) ? 1 : 0; }

template <typename T>
size_t countZero(T* p, size_t s, size_t e) {
  if (s == e) { return isZero(*p); }
  return (isZero(*p) + countZero(p+1, s+1, e));
}

int main() {
  int x[] = { 0, 1, 2, 4, 5, 0 , 56, 2 };
  std::cout << countZero(x, 0, 2) << std::endl;
  return 0;
}
