/*
Vectors have random access memory

Linked lists have pointers to the new nodes. A collection of nodes. Manager -> head (size and start of the node)
*/

#include <iostream>
template <typename T>
struct treenode_{
  treenode_() : treenode_(T()){}
  treenode_(const T& data, treenode_<T>* left=nullptr, treenode_<T>* right=nullptr) : data_(data), left_(left), right_(right){}
  friend bool operator<(const treenode_<T>& a, const treenode_<T>& b){ return a.data_ < b.data_; }
  friend std::ostream& operator<<(std::ostream& os, const treenode_<T>& node){
    return os << node.data_ << "(" << &node << ") Left: " << node.left_ << ", Right: " << node.right_ << ")";
  }
  T data_;
  treenode_<T>* left_;
  treenode_<T>* right_;

};
template <typename T>
class Tree{
  public:
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }


    void printInOrder(treenode_<T>* root){
      // sanity check
      if(root == nullptr){ return; }
      printInOrder(root->left_);
      std::cout << *root;
      printInOrder(root->right_);
    }
    void printInOrder(){ printInOrder(root_); }

    void printPreOrder(treenode_<T>* root){
      if(root == nullptr) { return; }
      std::cout << *root;
      printPreOrder(root->left_);
      printPreOrder(root->right_);
    }

  private:
    treenode_<T>* root_;
    size_t size_;
};
void printLevelOrder(){

}

void printPreOrder(){

}

void printPostOrder(){


}
void printInOrder(){


}
