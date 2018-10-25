# Linked List

## Functions needed
*some functions are not included in the standard library, I am not a software engineer*
## Constructing the object
- Default constructor
- Constructor with size parameter

## Accessors
- size : return the current size of the linked list by recursively traversing through the list until tail_ is NULL
- setSize : set the size of the linked list class

# Attributes and functionality
- empty : is linked list empty; if both head_ and tail_ point to NULL
- clear : recursively delete the nodes by advancing the head_ by one and assigning the new head_ to be head_
- append : adding element to the front of the tail_
- prepend : adding an element to the front of the first element, making it the new first node
- pop : delete the first element
- insert : add an element in a certain position
- createNode : creating a new node and placing it after the nth element in the linked list

# Elements
- size_ : current size of the linked list
- head_ : current head of the linked list
- tail_ : current tail of the linked list
