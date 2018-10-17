#include <iostream>
#include <algorithm>

template <typename T>
class V_ {
  public:
    // constructors and destructors

    V_() : size_(0){}
    V_(size_t C) : size_(0), capacity_(C) , data_(new T [C]){}
    V_ operator=(const V_& vector);
    ~V_();

    // accessors and mutators
    size_t size();
    void setSize(size_t s_);

    size_t capacity();
    void setCapacity(size_t cap_);

    T operator[](size_t index);
    T& operator[](size_t index) const;

    // attributes?
    bool empty();
    void clear();

    // functionality
    void resize(size_t size);
    void push(T data);
    void pop();
    void print();
    void copy(const V_<T>& other);
  private:
    size_t size_, capacity_;
    T* data_;
};
template <typename T>
V_<T>::~V_<T>(){ delete [] data_; data_ = nullptr; }

template <typename T>
size_t V_<T>::size() { return size_; }

template <typename T>
void V_<T>::setSize(size_t s_) { size_ = s_; }

template <typename T>
size_t V_<T>::capacity() { return capacity_; }

template <typename T>
T V_<T>::operator[](size_t index) { return(!empty()) ? data_[index] : throw new std::range_error("underflow"); }

template <typename T>
bool V_<T>::empty(){ return (size_ == 0) ? 1 : 0; }


template <typename T>
void V_<T>::pop(){
  if(size_ == 0) { throw new std::range_error("underflow"); }
  data_[size_--] = T();

}
template <typename T>
void V_<T>::clear(){
  if(!empty()){ pop(); }
}
template <typename T>
void V_<T>::resize(size_t size){
  if(data_ != nullptr){
  T* newData = new T[size];
  std::copy(_II __first, _II __last, _OI __result)
  clear();
  data_ = newData;
  size_ = size;
 }
}
template <typename T>
void V_<T>::copy(const V_<T>& other){

}
template <typename T>
void V_<T>::push(T data){
  if(size_ == capacity_){ resize(100); }
  data_[size_++] = data;
}

template <typename T>
void V_<T>::print() {
  for(size_t i=0; i < size(); ++i) { std::cout << data_[i] << std::endl;}
}
int main() {
  V_<int> vector(10);
  for(size_t i=0; i < 11; ++i){ vector.push(i); }
  vector.print();
  vector.resize(100);
  // std::cout << vector.size() << std::endl;
  return 0;
}
