#include <iostream>

template <typename T>
void swap(T *x, T *y){
  T tmp = *x;
  *x = *y;
  *y = tmp;
}

template <typename T>
void selectionSort(T* array, T index){
  size_t minimumIndex;
  for(size_t i = 0; i < index-1; ++i){
    minimumIndex = i;
    for(size_t j = i+1; j < index; ++j){
      if(array[j] < array[minimumIndex]){ minimumIndex = j; }
    }
    swap(&array[minimumIndex], &array[i]);
  }
}


int main() {
  size_t array[] = { 1, 3, 4, 2, 5 };
  size_t index = sizeof(array)/sizeof(*array);
  selectionSort(array, index);
  for(size_t i = 0; i < 5; ++i){
    std::cout << array[i] << std::endl;
  }
}
