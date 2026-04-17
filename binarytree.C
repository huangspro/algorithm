#include<iostream>

using namespace std;

template < typename T >
class node{
public: 
  node<T>* parent,* left,* right;
  int key = 0;
  T value = 0;
  
  node(int k, T value):parent(NULL), left(NULL), right(NULL), value(value), key(k){}
  
  void l(node* a){
    left = a;
  }
  
  void p(node* a){
    parent = a;
  }
  
  void r(node* a){
    right = a;
  }
  
  bool all_empty(){
    return left==NULL && right==NULL;
  }

};

template < typename T >
class BinaryTree{
  node<T>* root = NULL;
  
  T get_in(int key, node<T>* sub){ 
    if(sub == NULL)return NULL;
    if(sub->key==key)return sub->value;
    if(sub->all_empty())return NULL;
    else if(key > sub->key)return get_in(key, sub->right);
    else return get_in(key, sub->left);
  }
  
  void insert_in(node<T>* target, node<T>* sub){
    if(is_empty()){root = target;return;}
    if(sub->key > target->key){
      if(sub->left != NULL)insert_in(target, sub->left);
      else{
        sub->l(target);
        target->p(sub);
      }
    }else{
      if(sub->right != NULL)insert_in(target, sub->right);
      else{
        sub->r(target);
        target->p(sub);
      }
    }
  }
  
public:
  BinaryTree(){}
  
  T get(int key){
    if(is_empty())return NULL;
    return get_in(key, root);
  }
  
  void insert(int key, T value){
    insert_in(new node<T>(key, value), root);
  }
  
  bool is_empty(){
    return root==NULL;
  }
  
  
};

int main(){
  BinaryTree<double> B;
  B.insert(2, 10.5);
  B.insert(5, 11.5);
  B.insert(4, 12.5);
  B.insert(1, 13.5);
  B.insert(3, 14.5);
  for(int i=1;i<=5;i++){
    cout<<B.get(i)<<endl;
  }
}
