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
void Percolation::open(int row, int col){
 
        state[row * size + col] = true;
        int index = row * size + col;

        if (isOpen(row + 1, col)){  //down
            if (qu.find(index) != qu.find(index + size)){
                qu.myUnion(index, index + size);
            }
        }
        if (isOpen(row - 1, col)){  //up
            if (qu.find(index - 1) != qu.find(index)){
                qu.myUnion(index, index - size);
            }
        }
        if (isOpen(row, col + 1)){  //right
            if (qu.find(index) != qu.find(index + 1)){
                qu.myUnion(index, index + 1);
            }
        }
        if (isOpen(row, col - 1)){  //left
            if (qu.find(index) != qu.find(index - 1)){
                qu.myUnion(index, index - 1);
            }
        }
        if (row == 0){
            qu.myUnion(col, size * size);
        }
        if (row == size - 1){
            qu.myUnion(row * size + col, size * size + 1);
        }
}
void Percolation:: setQu(WeightedQuickUnionUF qu) {
  this->qu = qu;
}
bool Percolation::isOpen(int row, int col) {
  return state[row*size + col];
    
}

bool Percolation::isFull(int row, int col) {
  return !isOpen(row, col);}
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

