#include <iostream>
#include <functional>


size_t onezero(int a, const std::function<size_t(int)>& predicate) { return predicate(a) ? 1 : 0; }


size_t count(int *p, size_t start, size_t end, std::function<size_t(int)>& predicate){
  if(start == end) { return p[start]; }
  return predicate(p[start] + count(p, start+1 ,end, predicate));
}

int main() {
  int x[] = {1, 2, 3, 4, 4, 6 , 43, 532, 432};
  // size_t printMe = count(x, 0, 6, [](int a) { return (a % 2 == 0);});
  // std::cout << printMe << std::endl;
  count(x, 0, 6, [](int a) { return (a % 2 == 0);});
}
