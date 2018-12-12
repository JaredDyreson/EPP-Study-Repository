// Linear Probing
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#define MAX 1000

class Dog{
  public:
    Dog() : name_("Doggo"), age_(10){}
    Dog(std::string name) : name_(name), age_(1){}
    std::string name() { return name_; }
    size_t age() { return age_; }
  private:
    std::string name_;
    size_t age_;
    // operator==(Dog dog, nullptr)
};

class hash_brown{
  public:
    size_t hash(Dog dog){
      size_t counter = 0;
      for(auto e : dog.name()){ counter+=(size_t)e; }
      std::cout << counter << std::endl;
      return counter;
    }
    bool indexEmpty(size_t i) {
      // return table_.at(i).name().empty() ? 1 : 0;
      return table_.at(i) == nullptr;
    }
    size_t index(size_t h) { return h % table_.size(); }
    void insert(std::string n, Dog doggo){
      size_t h = hash(doggo);
      size_t i = index(h);
      if(indexEmpty(i)){ table_[i] = doggo; }
    }
    void print(){
      for(size_t i = 0; i < table_.size(); ++i){
        if(indexEmpty(i)){
          std::cout << i << std::endl;
        }
      }
    }
    std::array<Dog, MAX> table_;
};
