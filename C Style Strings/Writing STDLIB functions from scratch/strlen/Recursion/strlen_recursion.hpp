#include <iostream>

size_t strlen_(char *string, size_t n){
  // if the string is only one object deep
  if (string[n] == 0) { return n; }
  // continue iterating until you reach the end
  return strlen_(string, ++n); // size_t object
}
