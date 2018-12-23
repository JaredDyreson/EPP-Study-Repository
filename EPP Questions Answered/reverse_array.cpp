#include <iostream>
#include <string>

template <typename T>
void reverse(T arr[], size_t s, size_t e){
  while(s < e){
    T t = arr[s];
    arr[s] = arr[e];
    arr[e] = t;
    ++s;
    --e;
  }
}

template <typename T>
void print(T arr[], size_t s){
  for(size_t i = 0; i < s; ++i){
    std::cout << arr[i] << std::endl;
  }
}

void test(){
  int a[5] = { 1, 2, 3, 4, 5 };
  reverse(a, 0, 4);
  print(a, 5);
  std::cout << std::endl;
  reverse(a, 0, 4); // no u
  print(a, 5);
}
int main() {
  test();
  return 0;
}
