#include <iostream>

template <typename T>
void swap(T* x, T* y){
  // create a mediator pointer, to facilitate the swap
  T tmp = *x; // set it equal to the pointer of the pointer of x
  *x = *y; // set the value of the pointer to x to be the value of the pointer to y
  *y = tmp; // have the mediating pointer send its data back to x, thus completing the swap
}

void testSwap(){
  int a = 1;
  int b = 2;
  swap(&a, &b);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
}

int main() {

}
