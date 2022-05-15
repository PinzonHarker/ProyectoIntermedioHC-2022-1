#include <vector>
#include "percolation.h"
#include "WeightedQuickUnionUF.h"
#include <random>

Percolation::Percolation(){}

Percolation::Percolation(int n){
  this->size = n;
  this->qu = WeightedQuickUnionUF(n*n + 4);
  for (int i = 0; i < n*n; i++) {
    this->state.push_back(false);
  }
}

void Percolation::setSize(int size){
  this->size = size;
}
int Percolation::getSize(){
  return size;
}
WeightedQuickUnionUF Percolation::getQu(){
  return qu;
}
std::vector<bool> Percolation::getState(){
  return state;
}
void Percolation::setState(std::vector<bool> state) {
  this->state = state;
    
}
void Percolation::open(int index){
  state[index] = true;
  if(index<size*(size - 1)){
    if (isOpen(index + size)){  //down

      qu.myUnion(index, index + size);

    }
  }
  if(index>=size){
    if (isOpen(index-size)){  //up

      qu.myUnion(index, index - size);

    }
  }
  if(index%size != size-1){
    if (isOpen(index + 1)){  //right	

	qu.myUnion(index, index + 1);

    }
  }
  if(index%size != 0){
    if (isOpen(index-1)){  //left

      qu.myUnion(index, index - 1);

    }
  }
  
  if (index < size){
 
    qu.myUnion(index, size * size);

  }
  if(index%size == 0){

     qu.myUnion(index, size * size + 2);
    
  }
  if (index >= size*(size-1)){

    qu.myUnion(index, size * size + 1);

  }
  if(index%size == size-1){

    qu.myUnion(index, size * size + 3);

  }

}
void Percolation:: setQu(WeightedQuickUnionUF qu) {
  this->qu = qu;
}
bool Percolation::isOpen(int index) {
  return state[index];
    
}

bool Percolation::isFull(int index) {
  return !isOpen(index);
}
int Percolation::numberOfOpenSites() {
  int count = 0;
  for (int i = 0; i < state.size(); i++) {
    if (state[i]){
      count++;
    }
  }
        return count;
}
bool Percolation::percolates(){
   return
     qu.find(size * size) == qu.find(size * size + 1) ||
     qu.find(size * size + 2) == qu.find(size * size + 3);
}







   
