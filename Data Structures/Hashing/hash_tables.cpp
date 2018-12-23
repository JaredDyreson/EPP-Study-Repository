#include <iostream>
#include <string>
#include <algorithm>
#include <list>

template <typename H, typename V>
class Hash{
  public:
    // size_t size() { return arr}
    size_t hash(H h){
      size_t result = size_t(h[0]);
      size_t c=1;
      for(auto element : h){
        result = result*c + element;
        c++;
      }
      return result;
    }
    void put(H hashee, V value){
      size_t hashedValue = hash(hashee);
      size_t cellBlock = hashedValue % 53;
      // std::cout << hashedValue % 53 << std::endl;
      // arr.at(cellBlock) = value;
      if(arr.size() < cellBlock){
        arr.resize(cellBlock);
      }

      arr[cellBlock] = value;
      std::cout << "cell: " << cellBlock << std::endl;
      std::cout << "value: " << value << std::endl;
    }
    void print(){
      for(auto element : arr){
        std::cout << element << std::endl;
      }
    }

  private:
    std::list<V> bucket;
    std::vector<V> arr;
};

int main(){
  Hash<std::string, size_t> ha;
  ha.put(std::string("spot"), 100);
  ha.put(std::string("pots"), 100);
  // ha.print();
  return 0;
}
