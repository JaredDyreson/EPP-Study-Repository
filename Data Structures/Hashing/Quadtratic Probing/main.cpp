#include <iostream>
#include <string>

void quadtraticProbe(int* table_, int hash){
  // int array[10] = {0};
  // given the formula (i^2 + i + H(hash)) % sizeof(array)
  int index = hash % 10;
  for(int i = 0; i < 10; ++i){
    if(&table_[index] == NULL){
      table_[index] = index;
    }
  }
}

void print(int* table, int size_){
  for(int i = 0; i < size_; ++i){
    std::cout  << i << ": " << table[i] << std::endl;
  }
}


int main(){
  int array[10];
  quadtraticProbe(array, 20);
  print(array, 10);
  return 0;
}
