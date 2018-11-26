#include <iostream>

namespace J {
  #define MIN 10
  template <typename T>
  class string{
    public:
      string() : data_(nullptr), size_(0){}
      string(T* data) : data_(new T[MIN]), size_(MIN){}
      string operator=(const string<T>&); // copy constructor
      string operator=(T); // assignment operator
      ~string() { delete [] data_; data_ = nullptr; }

      size_t size();
      size_t size(T* data);

      T& begin();
      T& end();
      const T& begin() const;
      const T& end() const;

      T& operator[](size_t index);
      const T& operator[](size_t index) const;

    private:
      size_t size_;
      T* data_;
  };

  template<typename T>
  T& string<T>::begin(){ return data_; }

  template <typename T>
  const T& string<T>::begin() const { return data_; }

  template <typename T>
  T& string<T>::end() { return data_[size_-1]; }

  template <typename T>
  const T& string<T>::end() const { return data_[size_-1]; }


  template <typename T>
  T& string<T>::operator[](size_t index){
    if(index >= size_) { throw new std::range_error("overflow"); }
    return data_[index];
  }
  template <typename T>
  const T& string<T>::operator[](size_t index) const{
    if(index >= size_) { throw new std::range_error("overflow"); }
    return data_[index];
  }

  template <typename T>
  size_t string<T>::size(T* data){
    if(data == nullptr) { return 0; }
    return 1 + size(data+1);
  }
  template <typename T>
  size_t string<T>::size(){ return size(data_); }
}
