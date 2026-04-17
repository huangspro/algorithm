#include<iostream>

using namespace std;

template < typename T >
class node{
public: 
  node<T>* parent,* left,* right;
  int key = 0;
  T value = 0;
  
  node():parent(NULL), left(NULL), right(NULL){}
  
  void l(node* a){
    left = a;
  }
  
  void p(node* a){
    parent = a;
  }
  
  void r(node* a){
    right = a;
  }

};
template < typename T >
class BinaryTree{
  node<T>* root = NULL;
  
  T get(int key, node<T>* sub){
    if(sub == NULL)return NULL;
    if(sub.key==key)return sub.value;
    if(sub.left == NULL && sub.right == NULL)return NULL;
    if(sub.left == NULL || key > sub.left.key)get(sub.right);
    else if(key < sub.left.key)get(sub.left);
  }
  
  void insert(){
    
  }
};

int main(){

}
