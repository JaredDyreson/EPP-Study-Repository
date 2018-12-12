#include <iostream>
#include <string>
#define MAX 43

class hash_brown{
  public:
    size_t index(size_t h) { return h % MAX; }
    void insert(size_t number){
      if(number == 0 || number == MAX) { return; }
      size_t i = index(number);
      while(&table_[i] != nullptr && table_[i] != number && table_[i] != -1){
        ++i;
        i %= MAX;
      }
      if(&table_[i] == nullptr || table_[i] == -1){
        std::cout << "Full" << std::endl;
        return;
      }
      else{
        table_[i] = number;
      }


    }
    void print(){
      for(size_t i = 0; i < MAX; ++i){
        if(table_[i] != 0) {
          std::cout << i << ": " << table_[i] << std::endl;
        }
      }
    }
    size_t table_[MAX] = {0};
    size_t size_;
};


int main() {
  hash_brown h;
  h.insert(1);
  h.insert(10);
  h.insert(12);
  h.print();
  return 0;
}
