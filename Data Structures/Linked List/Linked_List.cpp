#include <iostream>
#include <iomanip>
#include <string>

template <typename T>
struct node{
  node(){}                // default ctor
  node<T>* next_;
  T data_;
};

template <typename T>
class linked{
  public:
    linked() : head_(), tail_(), size_(0){}
    size_t size();

    void createNode(T value);
    void insert(T value);
  private:
    node<T>* head_ = nullptr;
    node<T>* tail_ = nullptr;
    size_t size_;
};


template <typename T>
size_t linked<T>::size() { return size_; }

template <typename T>
void linked<T>::createNode(T value){
  node<T> *tmp = new node<T>;
  tmp->data_ = value;
  tmp->next_ = nullptr;
  if(head_ == nullptr) {
    head_ = tmp;
    tail_ = tmp;
    tmp = nullptr;
  }
  head_->next_ = tmp;
  tmp->next_ = tail_;
  // tail_->next_ = nullptr;
}
template <typename T>
void linked<T>::insert(T value){
  // if node is not head

}

int main(){
  linked<int> l;
  l.createNode(10);
}
