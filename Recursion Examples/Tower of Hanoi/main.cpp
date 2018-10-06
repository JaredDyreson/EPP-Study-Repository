#include <stack>
#include <iostream>
int function(){
  // std::stack<int> src = { 6, 5, 4, 3, 2, 1 }, tmp, dst;
  std::stack<int> src;
  return 0;
}

void moveone(std::stack<int>& src, std::stack<int>& dest){
  int value = src.top();
  src.pop();
  dest.push(value);
}
void move(std::stack<int>& src, std::stack<int>& destination, std::stack<int>& tmp, size_t number){
  if(number == 1) { moveone(src, destination); return; }
  move(src, destination, tmp, --number);
  moveone(src, destination);
  move(tmp, destination, number-1);
}

int main(){
  
}
