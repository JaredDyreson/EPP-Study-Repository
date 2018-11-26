// https://www.slideshare.net/Abrish06/graph-48747573
// https://www.slideshare.net/anujmodi555/graphs-in-data-structure

#include <vector>
#include <iostream>

template <typename T>
void printMatrix(std::vector<std::vector<T>> a){
  for(auto& row : a){
    for(auto subRow : row){ std::cout << subRow << " "; }
    std::cout << std::endl;
  }
}

int main(){
  std::vector<std::vector<bool>> a {{1, 0, 1, 0}, {0, 1, 0, 1}};
  printMatrix(a);
  return 0;
}
