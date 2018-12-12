// Linear Probing
#include <iostream>
#include <string>
#define MAX 100
class Dog{
  public:
    Dog() : name_("Doggo"), age_(10){}
    Dog(std::string name) : name_(name), age_(1){}
    std::string name() { return name_; }
    size_t age() { return age_; }
  private:
    std::string name_;
    size_t age_;
};

class hash_brown{
  public:
    size_t hash(Dog dog){
      size_t counter = 0;
      for(auto e : dog.name()){ counter+=(size_t)e; }
      return counter;
    }
    size_t index(size_t h) { return h % MAX; }
    void insert(std::string n, Dog doggo){
      size_t h = hash(doggo);
      std::cout << "Hash: " << h << std::endl;
      size_t i = index(h);
      std::cout << "Index: " << i << std::endl;
      if(table_[i].name().empty()){ table_[i] = doggo; std::cout << "inserted " << doggo.name() << std::endl; }
    }
    void print(){
      for(size_t i = 0; i < MAX; ++i){
        if(&table_[i] != nullptr) {
          std::cout << table_[i].name() << std::endl;
        }
      }
    }
    Dog table_[MAX] = {};
};
