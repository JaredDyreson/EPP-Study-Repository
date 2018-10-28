#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

void write(){
  std::ofstream stream("i am root");
  if(!stream.is_open()){ std::cerr << "cannot open file coward!" << std::endl; exit(1); }
  stream << "whoami" << std::endl;
  stream << "==" << std::endl;
  stream << "root" << std::endl;
  stream.close();
  std::fstream read("i am root");
  std::string line;
  while(std::getline(read, line)) { std::cout << line << std::endl; }
  read.close();
  return;
}
int main() {
  write();
  return 0;

}













































void space(){
  char selection = '\0';
  do{
    std::cout << "Pick A or Q: ";
    std::cin >> selection;
    switch(selection){
      case 'A':
        std::cout << "A" << std::endl;
        break;;
      case 'Q':
        break;;
      default:
        std::cerr << "try again bitch" << std::endl;
        break;;
    }
  } while(selection != 'Q');
}
