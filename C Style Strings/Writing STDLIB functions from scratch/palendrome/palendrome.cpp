#include <iostream>

bool isPalendrome(char* array){

  return false;
}
bool isPalendromeRecursion(char* array, size_t start, size_t end){
  if(start == end) { return true; }
  return array[start] == array[end] ? true:false;
}
int main() {
  char array[10] = "racecar";
  std::cout << isPalendromeRecursion(array, 0, 7) << std::endl;
}
