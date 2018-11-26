#include <iostream>
#include <string>

// hook into a current library to add extended functionality to it. An idea i cooked up late at night
class K : public std::string{
public:
  void print(){
    std::cout << K::size() << std::endl;
  }

};

int main() {
 K jared;
 jared.print();
}
