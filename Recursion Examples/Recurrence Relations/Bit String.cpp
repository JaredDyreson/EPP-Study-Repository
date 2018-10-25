#include <iostream>

template <typename T>
bool logic(T value) { return (value == 1) ? 1 : 0; }
size_t weight(bool* p, size_t s, size_t e){
  if(s == e) { return logic(*p); }
  return logic(*p) + weight(p+1, s+1, e);
}

int main(){
  bool a[] = { 1, 0, 1, 0, 1 };
  std::cout << weight(a, 0, 4) << std::endl;
  return 0;
}
