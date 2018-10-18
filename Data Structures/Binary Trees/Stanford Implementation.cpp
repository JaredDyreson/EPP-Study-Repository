// refer here . http://cslibrary.stanford.edu/110/BinaryTrees.html
#include <iostream>


struct node {
  int data;
  node* left = nullptr;
  node* right = nullptr;
};

void build123(){
  // this builds a simple tree that looks like this
  /*
     2
    / \
   1   3

  */
  node head_, leafOne, leafTwo;
  head_.data = 2;
  leafOne.data = 1;
  leafTwo.data = 3;
  if(leafOne.data <= head_.data){ head_.left = &leafOne; }
  else if(leafOne.data > head_.data){ head_.right = &leafOne; }
  head_.right = &leafTwo;
  // else{ head_.left = nullptr; head_.right = nullptr;  }
  std::cout << "  " << head_.data << std::endl;
  std::cout << " /" << " \\" << std::endl; // must use \\ because of return carriages
  std::cout <<  head_.left->data << "   " << head_.right->data << std::endl;
}
int main() {
  build123();
  return 0;
}
