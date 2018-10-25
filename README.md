# EPP-Study-Repository
This is where we collaborate and attempt to not fail this damn test.

Or Jared just writes it all thats totally fine - 10/24/2018

#NOTE
Just found that you can bring a book to the test, please take advantage of this!!
The book I and two others used was called Data Structures And Algorithms In C++ (Custom) by Michael T. Goodrich

The used copy was only $33.00
# Script to maintain git repositories
The included file called commit can be dropped in your /usr/bin folder or creating a new path and adding it to PATH in your bashrc or whatever shell's default configuration file is
```bash
export PATH=$PATH:/home/$USER/scripts
```
The above scenario does work so go at it, be more productive and have a cleaner git repo

Adding this file also is a sanity check just in case my computer crashes, I love this script
# To clone
```bash
git clone https://github.com/JaredDyreson/EPP-Study-Repository.git
```

# Topics
- standard control structures for assignment, selection, repetition
- functions
- input and output to and from text and binary files
- arrays and strings
- pointers and dynamic variables
- recursion
- classes and objects of the classes
- templates
- operator overloading
- lists, stacks, queues, binary trees with both array and linked list implementations
- searching and sorting

_Please DO NOT use namespace std at all costs, it makes your code hard to read!!_

# COMPILING
For the unitiated, this was written under the assumption that Linux is your daily driver. Hopefully you can compile these in Windows, if not....well, find a way.
```bash
clang++ -std=c++14 [input].cpp -o output
```
