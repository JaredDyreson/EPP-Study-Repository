#include <iostream>
#include <iomanip>
// Look To the "find" and "tree" commands in Linux, these are Teractive ways to understand binary trees using the filesystem, very Teresting to look at
// Other material to look To for CS majors : parent processes in Linux and filesystem hierarchy
/*
The difference between AVL trees and BST is that an AVL tree has efficient rebalancing factor to it
*/
/*
notes from zybooks reading
  - a node without children is called a leaf
  - a node with at least one child is called an Ternal node
  - a node with children is called the parent (along with being the Ternal node)
  */


template <typename T>
struct node{
  T key_;
  struct node<T>* left;
  struct node<T>* right;
  node(T d) : key_(d), left(nullptr), right(nullptr){}
  node() : key_(NULL), left(nullptr), right(nullptr){};
};

template <typename T>
class Tree{
  public:
    Tree() : root_(nullptr) {}
    size_t size() { return size_; }
    bool empty() { return (size_ == 0) ? 1 : 0; }
    struct node<T>* root() { return root_; }
    static T lookup(struct node<T> *root, T target){
      if(root == nullptr){ return false; }
      else{
        if(target == root->key_) { return true; }
        else{
          if(target < root->key_) { return lookup(root->left, target); }
          else { return lookup(root->right, target); }
        }
      }
    }
    struct node<T>* newNode(T key){
      node<T>* n = new struct node<T>(key);
      ++size_;
      if(root_ == nullptr){ root_ = n; }
      return n;
    }
    struct node<T>* insert(struct node<T>* root, T key){
      if(root == nullptr) { return newNode(key); }
      else{
        // size_t balanceFactor = height(root->left) - height(root->right);
        // if(balanceFactor == 1 || balanceFactor == size_t(-1) || balanceFactor == 0){ std::cout << "balanced" << std::endl; }
        if(key < root->key_) { root->left = insert(root->left, key); }
        else{ root->right = insert(root->right, key); }
        ++size_;
        return root;
      }
    }

    size_t height(node<T>* node){
      if(node == nullptr) { return 0; }
      size_t leftHeight = height(node->left);
      size_t rightHeight = height(node->right);
      if(leftHeight > rightHeight) { return leftHeight+1; }
      return rightHeight+1;
    }
    void remove(node<T>* r, const T& data){
      if(r == nullptr) { return; }
      if(size() == 1 && r->key_ == data) { delete r; --size_; return; }
      if(data < r->key_) { Tree::remove(r->left, data); return; }
      else if(data > r->key_) { Tree::remove(r->right, data); return; }
    }
    size_t countNoChildren(node<T> *n) const{
      if(n == nullptr) { return 1; }
      size_t left = countNoChildren(n->left);
      size_t right = countNoChildren(n->right);
      return left + right + (root_->left == nullptr && root_->right == nullptr ? 1 : 0);
    }
    size_t countNoChildren()const{
      // if node has a left AND right nodes that point to NULL!
      return countNoChildren(root_);
    }
    size_t count_levels() const{ return count_levels(root_); }

    size_t count_levels(node<T>* r) const{
  	   if(r == nullptr) { return 0; }
  	   return 1 + std::max(count_levels(r->left), count_levels(r->right));
    }

    struct node<T>* search(node<T>* root_, T key){
      if(root_->key_ == key || root_ == nullptr) { return root_; }
      if(key < root_->left) { return search(root_->left, key); }
      return search(root_->right, key);
    }
    void printNode(node<T>* node, std::ostream& out){ out << node->key_ << std::endl; }

    T min(node<T>* root){
      if(root == nullptr) { return root->key_; }
      while(root->left != nullptr){ root = root->left; }
      return root->key_;
    }
    T max(node<T>* root){
      if(root == nullptr) { return root->key_; }
      while(root->right != nullptr) { root = root->right; }
      return root->key_;
    }
    size_t size(node<T>* js){
      if(js == nullptr) { return 0; }
      return (size(js->left) +1 + size(js->right));
    }
    size_t size() const{ return size(root_); }
    // printing mechanics
    void inOrder(node<T>* node){
      if(node == nullptr){ return; }
      inOrder(node->left);
      std::cout << node->key_ << std::endl;
      inOrder(node->right);
    }

    void preOrder(node<T>* node){
      if(node == nullptr){ return; }
      std::cout << node->key_ << std::endl;
      preOrder(node->left);
      preOrder(node->right);
    }

    void postOrder(node<T>* node){
      if(node == nullptr){ return; }
      postOrder(node->left);
      postOrder(node->right);
      std::cout << node->key_ << std::endl;
    }

    void levelOrder(node<T>* node){
      size_t height_ = height(node);
      for(size_t i=0; i <= height_; ++i){
        printGivenLevel(node, i);
      }
    }
    void printGivenLevel(node<T>* node, size_t level){
      if(node == nullptr) { return; }
      if(level == 1) { std::cout << node->key_ << std::endl; }
      else if(level > 1){
        printGivenLevel(node->left, level-1);
        printGivenLevel(node->right, level-1);
      }
    }

  private:
    node<T>* root_, *traverse_;
    size_t size_ = 0, height_ = 0;
};

int main() {
  Tree<int> t;
  // t.insert(t.root(), 10);
  // t.insert(t.root(), 9);
  // t.insert(t.root(), 8);
  for(size_t i = 0; i < 99; ++i){ t.insert(t.root(), i); }
  std::cout << "height of tree is: " << t.height(t.root()) << std::endl;
  // std::cout << "Min value: " << t.min() << std::endl;
  // std::cout << "In order: " << std::endl;
  // t.inOrder(t.root());
  // std::cout << std::endl;
  // std::cout << "Preorder: " << std::endl;
  // t.preOrder(t.root());
  // std::cout << std::endl;
  // std::cout << "Post order: " << std::endl;
  // t.postOrder(t.root());
  // std::cout << std::endl;
  //
  // std::cout << "Level Order: " << std::endl;
  // t.levelOrder(t.root());

  // t.printNode(t.root(), std::cout);
  std::cout << "Min: " << t.min(t.root()) << std::endl;
  std::cout << "Max: " << t.max(t.root()) << std::endl;
  std::cout << "Size: " << t.size(t.root()) << std::endl;
  return 0;
}

/*
Preorder - P L R
In Order - L P R
Post Order- L R P
Level order - print each of the levels
*/
