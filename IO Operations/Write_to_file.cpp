// basically making a copy of a file but for simplicity's sake, don't worry
// and no sanity checks either so yeah :)
#include <fstream>
#include <string>
int main(){
  std::string line;
  std::ofstream write("write_here");
  std::fstream stream("text_file");
  while(std::getline(stream, line)){ write << line << std::endl; }
  write.close();
  stream.close();
  return 0;
}
