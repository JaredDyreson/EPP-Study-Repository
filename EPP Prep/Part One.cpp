#include <iostream>
#include <string>
#include <fstream>
struct Contestant{
  std::string name;
};

int main(){
  std::string line;
  std::fstream stream("dsjdss");
  while(std::getline(stream, line)) { std::cout << line << std::endl; }
}
