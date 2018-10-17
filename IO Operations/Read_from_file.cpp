#include <iostream>
#include <fstream>
#include <string>
int main() {
  std::string line;
  std::fstream stream("text_file");
  while(std::getline(stream, line)){ std::cout << line << std::endl; }
  stream.close();
  return 0;
}
