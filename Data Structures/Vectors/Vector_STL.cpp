#include <vector>
#include <iostream>

// demonstrates that the vector will auto resize
int main() {
  std::vector<int> vector_(8);
  for(size_t i = 0; i < 10; ++i) {
    vector_.push_back(i);
  }
  // for most containers that have a begin and end, use the auto feature in C++11 and higher
  for(auto element : vector_ ){
    std::cout << element  << std::endl;
  }
  std::cout << vector_.size() << std::endl;
  return 0;
}
