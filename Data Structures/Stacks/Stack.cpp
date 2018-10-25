// sorry for the syntax, I couldn't help it :}
#include <iostream>

template <typename T>
struct node{
  node(T value) : data_(value), next_(nullptr){}
  node() : node(0){}
  T data_;
  node<T>* next_;
};

template <typename T>
class stack{
  public:
    stack() : size_(0), head_(nullptr){}
    bool empty();
    size_t size();
    T top();
    void push(T value);
    void pop();
    ~stack(){}
  private:
    size_t size_;
    node<T>* head_, *tail_;
};


template <typename T>
bool stack<T>::empty() { return (size_ == 0) ? 1 : 0; }

template <typename T>
size_t stack<T>::size() { return size_; }

template <typename T>
T stack<T>::top() { (!empty()) ? head_->data : 0; }

template <typename T>
void stack<T>::push(T value) {
  node<T>* newNode = new node<T>(value);
  newNode->data_ = value;
  newNode->next_ = head_;
  head_ = newNode;
}

template <typename T>
void stack<T>::pop(){
  node<T> *current = new node<T>;
  node<T> *previous = new node<T>;
  current = head_;
  while(current->next_ != nullptr){
    previous = current;
    current = current->next_;
  }
  tail_ = previous;
  previous->next_ = nullptr;
  delete current;
}
int main() {
  stack<int> george;
  george.push(1);
  george.pop();
}
