// this is using the STL to understand what is going on
// https://www.techiedelight.com/graph-implementation-using-stl/
#include <iostream>
#include <list>
#include <vector>
#include <ostream>
#include <cmath>



struct Edge{
  int source_, destination_, weight_;
};


class Graph{
  public:
    enum direction { visited=0, unvisited=1, discovery=2, back=3 };
    Graph(){}
    Graph(const std::vector<Edge> &edges, int n){
      adjacencyList.resize(n);
      for(auto &edge : edges){
        adjacencyList[edge.source_].push_back(edge.destination_);
      }
    }
    void print(std::ostream& out){
      for(size_t i = 0; i < adjacencyList.size(); ++i){
        if(adjacencyList[i].empty()){ break; }
        out << i  << " ->";
        for(auto element : adjacencyList[i]){ out << " " << element; }
        out << std::endl;
      }
    }

    void bfs(int site_){
      // visited.resize(site_);
      // for(auto i : visited) { i = 0; }
      // std::cout << "Visited Size: " << visited.size() << std::endl;
      // std::list<size_t> q_;
      // visited.at(site_) = true;
      // q_.push_back(site_);
      // std::list<size_t>::iterator i;
      // while(!q_.empty()){
      //   site_ = q_.front();
      //   std::cout << site_ << std::endl;
      //   q_.pop_front();
      // }
    }
    void test(){
      std::vector<Edge> edge{
        {0, 1} , { 1, 2 }, { 2, 0 }, {2, 1}, { 2, 3 }, { 3, 1 }, { 3, 2 }, { 3, 3 }

      };
      size_t n = edge.size();
      std::cout << "Initializing class with edges and amount of edges...." << std::endl;
      Graph g(edge, n);
      std::cout << "Edges: " << edge.size() << std::endl;
      // std::cout << "Vertices: " << n << std::endl;6
      std::cout  << "Printing graph..." << std::endl;
      std::cout << std::endl;
      g.print(std::cout);
    }
  private:
    std::vector<std::vector<int>> adjacencyList;
    std::vector<bool> visitedNodes;
    std::vector<Edge> edges;
};
