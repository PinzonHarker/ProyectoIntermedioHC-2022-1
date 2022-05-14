#include <vector>
#include "percolation.h"
#include "WeightedQuickUnionUF.h"

Percolation::Percolation(int n){
  this->size = n;
  this->qu = WeightedQuickUnionUF(n*n + 2);
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
        //int index = row * size + col;

        if (isOpen(index + size)){  //down
	  //if (qu.find(index) != qu.find(index + size)){
             qu.myUnion(index, index + size);
		// }
        }
        if (isOpen(index-size)){  //up
	  //if (qu.find(index - 1) != qu.find(index)){
	    qu.myUnion(index, index - size);
		// }
        }
        if (isOpen(index + 1)){  //right
	  //if (qu.find(index) != qu.find(index + 1)){
             qu.myUnion(index, index + 1);
		//}
        }
        if (isOpen(index-1)){  //left
	  //if (qu.find(index) != qu.find(index - 1)){
            qu.myUnion(index, index - 1);
		//}
        }
        if (index < size){
            qu.myUnion(index, size * size);
        }
        if (index >= size*(size-1)){
            qu.myUnion(index, size * size + 1);
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
   return qu.find(size * size) == qu.find(size * size + 1);
}

