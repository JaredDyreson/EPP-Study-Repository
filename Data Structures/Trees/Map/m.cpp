#include <iostream>
#include <map>
#include <string>

#define NL std::cout << std::endl
int main() {
  std::map<size_t, std::string> mymap;
  std::cout << "mymap size: " << mymap.size() << std::endl;
  NL;
  mymap.insert(std::pair<size_t, std::string>(100, "Jared"));
  for(auto element : mymap){
    std::cout << "Key: " << element.first << std::endl;
    std::cout << "Value: " << element.second << std::endl;
  }
  NL;
  std::cout << "mymap size: " << mymap.size() << std::endl;
  return 0;
}
