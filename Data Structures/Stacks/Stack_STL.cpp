#include <stack>
#include <iostream>

int main() {
  std::stack<size_t> stackem;
  for(size_t i=0; i < 10; ++i){ stackem.push(i); }
  for(size_t i=0; i < 10; ++i) {
    std::cout << stackem.top() << std::endl;
    stackem.pop();
  }
  if(stackem.empty()){ std::cout << "The stack is now empty" << std::endl; }
}
