#include<iostream>
#include<vector>

using namespace std;

class Heap{
public:
  vector<int> data;
  int number;

  Heap(int n):number(n){}
  Heap(vector<int> d):data(d), number(d.size()){}
  
  void exch(vector<int>& a, int i, int j){
    int tem = a[i];
    a[i] = a[j];
    a[j] = tem;
  }
  
  // after one modification, subnode > parentnode, then fix it
  void swim(int k){
    if(k==0)return;
    if(data[(k-1)/2]<data[k]){
      exch(data, (k-1)/2, k);
      swim((k-1)/2); 
    }
  }
  
  // after one modification, subnode > parentnode, then fix it
  void sink(int k){
    if(2*k+1>number-1)return;
    int j=2*k+1;
    if(2*k+2<=number-1 && data[2*k+1] < data[2*k+2])j++;
    if(data[j]>data[k]){
      exch(data, k, j);
      sink(j);
    }else return;
  }
  
  void make(){
    for(int i=number/2-1;i>=0;i--){
      sink(i);
    }
  }
  
  int max(){
    return data[0]; 
  }
  
  int delMax(){
    int max = data[0];
    data[0] = data[data.size()-1];
    number--;
    data.pop_back();
    sink(0);
    return max;
  }
  
  void print(){
    for(int i=0;i<number;i++){
      cout<<data[i]<<" ";
    }
    cout<<endl;
  }
  
  int size(){
    return number;
  }
  
  void insert(int value){
    data.push_back(value);
    number++;
    swim(number-1);
  }
  
};

int main(){
  vector<int> D = {1,2,3,4,5,6,7,8,9,11};
  Heap h(D);

}
