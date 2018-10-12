#include <iostream>

template <typename T>
size_t product(T* a, size_t s, size_t e){
  if(s == e) { return *a; }
  return *a * product(a+1, s+1, e);
}

int main() {
  int x[] = {1, 2, 3, 4};
  std::cout << product(x, 0, 3) << std::endl;
  return 0;
}
