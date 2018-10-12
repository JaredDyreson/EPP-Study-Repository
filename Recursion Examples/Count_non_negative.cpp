#include <iostream>

// templated and will work for all int types
template <typename T>
size_t isNegative(T value) { return value < 0 ? 1:0; }
template <typename T>
size_t negativeCounter(T *p, size_t start, size_t end){
  if(start == end) { return isNegative(*p); }
  return(isNegative(*p) + negativeCounter(p+1, start+1, end));
}

int main() {
  double x[] = { -1, -2, -3, 6 };
  int xI[] = { -1, -2, -3, 6 };
  std::cout << negativeCounter(x, 0, 3) << std::endl;
  std::cout << negativeCounter(xI, 0, 3) << std::endl;
  return 0;
}
