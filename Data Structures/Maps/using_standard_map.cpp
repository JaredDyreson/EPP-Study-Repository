// Use a map when you need an associated value attached to a key, such as a player on a 2-D plane
// Key - Player entity
// Value - X, Y coordinates
// For this however, you do need to have a compare function for this to work

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
