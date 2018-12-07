// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/
// https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
// https://www.youtube.com/watch?v=shs0KM3wKv8
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <array>
#define MAX 10


class Student{
  public:
    Student(std::string s) { name_ = s; }
    Student();
    char grade() { return grade_; }
    void grade(char g){ grade_ = g; }
    std::string name() { return name_; }
    void name(std::string name) { name_ = name; }
  private:
    char grade_ = 'A';
    std::string name_;
};

class Hash{
  public:
    size_t hash(std::string key) {
      size_t h = 0;
      for(auto c : key){ h+=(int)c; }
      return h;
      // return reinterpret_cast<T>(key) % tableSize_;
    }
    template <typename T>
    size_t convertToIndex(T hashCode){
      for(size_t i =0; i < arr.size(); ++i){
        if((hashCode % tableSize_) == i) { return i; }
      }
      return -1;
    }
    bool put(std::string key_, Student student){
      size_t hash_ = Hash::hash(key_);
      size_t index_ = Hash::convertToIndex(hash_);
      if(index_ > MAX) { throw new std::range_error("Make this a freaking vector"); }
      arr[index_].push_back(student);
      return true;
    }
    void deleteItem(std::string key_){
      size_t hash_ = Hash::hash(key_);
      size_t index_ = Hash::convertToIndex(hash_);
      for(size_t i = 0; i < tableSize_; ++i){
        if((index_ % tableSize_) == i) {
          for(auto it = arr[i].begin(); it != arr[i].end(); ++it){
            if(key_ == it->name()){ arr[i].erase(it); break; }
          }
        }
      }
    }
    size_t getTableSize() { return tableSize_; }
    void print(){
      for(std::size_t i =0; i != tableSize_; ++i){
        std::cout << i << ": ";
        for(std::size_t j = 0; j < arr[i].size(); ++j){
          auto begin = arr[i].begin();
          std::advance(begin, j);
          std::cout << begin->name() << " ";
        }
        std::cout << std::endl;
      }
    }
  private:
    std::array<std::list<Student>, MAX> arr;
    size_t tableSize_ = arr.size();
};


int main() {
  Hash h;
  Student s1("Damery");
  Student s2("Miguel");
  Student s3("Matt");
  Student s4("Cooper");
  Student s5("Jared");
  h.put(s1.name(), s1);
  h.put(s2.name(), s2);
  h.put(s3.name(), s3);
  h.put(s4.name(), s4);
  h.put(s5.name(), s5);
  std::cout << "Table Size: " << h.getTableSize() << std::endl;
  std::cout << std::endl;
  h.print();
  h.deleteItem("Jared");
  std::cout << std::endl;
  std::cout << "Removed key Jared.."<< std::endl;
  std::cout << std::endl;
  h.print();
  return 0;
}
