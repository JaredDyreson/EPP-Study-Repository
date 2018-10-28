#include <iostream>
#include <string>
#include <sstream>

int main(){
  std::string s("10");
  std::stringstream ss(s);
  int counter = 1, tmp;
  while(ss >> tmp){
    counter+=tmp;
  }
  std::cout << counter << std::endl;

  return 0;
}
