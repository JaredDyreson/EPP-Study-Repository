#include <iostream>
#include <string>

int main() {
  std::string name =  "Queso Grande";
  std::cout << name << std::endl;
  // using range based for loop with auto
  for(auto element : name){
    std::cout << element << std::endl;
  }
  for(size_t i = 0; i < name.size(); ++i){
    std::cout << name[i] << std::endl;
    // you can treat it like a C style array
  }
  return 0;
}
