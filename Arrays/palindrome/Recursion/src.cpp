#include <iostream>
// do not use string library!

size_t strlen_(char *string, size_t n){
  if (string[n] == 0) { return n; }
  return strlen_(string, ++n);
}

bool palidrome(char *string, size_t n){
  if (n == 1) { return false; }
  size_t SIZE = strlen_(string, n);
  return ((string[n] == string[SIZE--] ? (palidrome(string, ++n)): false));
}
int main(int argc, char* argv[]){
  // if(argc == 0) { throw new std::logic_error("underflow"); }
  // size_t SIZE = strlen_(argv[1],0);
  // char *reverse = new char[SIZE];
  // for(size_t i=0; i  < 1; i++){
  //   std::cout << argv[1][SIZE--] << std::endl;
  // }
  // delete [] reverse;
  // return 0;
  if(palidrome(argv[1], 0)){ std::cout << "yes" << std::endl; }
  else  { std::cerr << "no" << std::endl;}
  return 0;
}
