#include <iostream>
// negative and divisble by 15
// time completed 1:55 but function was broken so attempt two below
bool logic(int value) { return (value < 0 && value % 15 == 0) ? 1 : 0; }

size_t counter(int* p, size_t s, size_t e){
  if(s == e) { return logic(*p);}
  return logic(*p) + counter(p+1, s+1, e);
}

// multiple of 17 and positive
// written in 1:51, slightly broken

bool hi(int value){ return (value > 0 && value % 17 == 0) ? 1 : 0; }

size_t adt(int *p, size_t s, size_t e){
  if(s == e) { return hi(*p); }
  return hi(*p) + adt(p+1, s+1, e);
}


// count all zeros
// written in 1:10 and not broken

bool zero(int value) { return (value == 0) ? 1 : 0; }
size_t fif(int* p, size_t s, size_t e){
  if(s == e) { return zero(*p); }
  return zero(*p) + fif(p+1, s+1, e);
}
int main() {
  int arr[] = { -15, 0, -46 };
  std::cout << fif(arr, 0, 2) << std::endl;
}
