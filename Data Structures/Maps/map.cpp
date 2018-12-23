#include <iostream>
#include <string>
#include <vector>


template <typename K, typename V>
struct pair{
  K key_;
  V value_;
  pair(K key, V value): key_(key), value_(value){}
  pair() : key_(nullptr), value_(nullptr){}
  friend std::ostream & operator << (std::ostream &out, const pair &p){
    out << "Key: " << p.key_ << std::endl;
    out << "Value: " << p.value_ << std::endl;
    return out;
  }
};

template <typename K, typename V>
class Map{
  public:
    Map(K key, V value){ pairVector.emplace_back(pair<K, V>(key, value)); }
    size_t size() { return pairVector.size(); }
    bool empty() { return pairVector.empty(); }
    typename std::vector<pair<K, V>>::iterator find(K key){
      for(auto i = pairVector.begin(); i != pairVector.end(); ++i){
        if(i->key_ == key){ return i; }
      }
      return pairVector.end();
    }
    void put(K key, V value){
      pairVector.emplace_back(pair<K, V>(key, value));
    }
    void print(){
      for(auto element : pairVector){
        std::cout << element << std::endl;
      }
    }
    void erase(K key){
      auto result = find(key);
      if(result == pairVector.end()){
        std::cout << "cannot remove value not in the map" << std::endl;
        return;
      }
      pairVector.erase(result);
    }
    typename std::vector<pair<K, V>>::iterator begin(){ return pairVector.begin(); }
    typename std::vector<pair<K, V>>::iterator end(){ return pairVector.end(); }

  private:
    std::vector<pair<K,V>> pairVector;
};


int main(){
  Map<int, std::string> map(1, std::string("one string"));
  map.put(2, std::string("another string"));
  if(!map.empty()){
    map.print();
  }
  map.erase(2);
  if(!map.empty()){
    map.print();
  }
  for(auto element : map){
    std::cout << element << std::endl;
  }
  return 0;
}
