#include <iostream>
#include <vector>
#include <list>
#include "../../Data Structures/Graphs/Graph.hpp"

void BFS(std::vector<std::list<size_t>> adjacencyList, int parent[], int level[]){
  std::list<size_t>::iterator iterator;
  size_t i_, par_, lev_;
  bool flag_ = true;
}

int main(){
  Graph g;
  g.test();
  // g.BFS(6);
  g.bfs(2);
  return 0;
}
