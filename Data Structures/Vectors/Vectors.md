# Functions needed

## Constructing the Object
- Default Constructor
- Constructor with capacity pass in
- Assignment operator/copy constructor
- Destructor (deep delete)

## Accessors
- size : return current size of the vector (not capacity)
- capacity : return capacity (total number of elements)
- setSize : set the size of the vector object
- setCapacity : set the total capacity size for the vector object


# Operators
- ostream operator "<<" : print the vector
- [] operator : access element at index (const and non const)

# Attributes and functionality
- empty : check if the vector is empty (check the size not capacity)
- clear : clear the vector
- resize : dynamically allocate a new T* array on the heap and delete the old T* array
- push : add element of type T to the vector
- pop : remove the last element of the array (LIFO model)
- print : same as overloaded ostream operator but you can call the function from the object
- copy : back-end for the copy constructor

## Elements
- size_ : current number of elements
- capacity_ : maximum amount of elements that can be stored in the vector
- T* data_ : a dynamically allocated array of an variable data type
