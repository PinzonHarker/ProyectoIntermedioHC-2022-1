#include "../libs/percolation.h"
#include "../libs/WQUF.h"
#include <vector>
#include <random>


/**                                                                                                                                                                                 
 * Default constructor don't initializes the Percolation object.
 */


Percolation::Percolation() {}

/**                                                                                                                                                                                 
     * Initializes an Percolation create objects quT and qu
     * with argumens {code n*n+2}, and set all {@code n*n}
     * state false {@code n*n} elements {@code 0} through {@code n*n-1}.                                     
     *                                                                                                                                           
     * @param  n the number of elements                                                                                                                                             
     * @throws IllegalArgumentException if {@code n < 0}                                                                                                                                 */

Percolation::Percolation(int n)
{
  this->size = n;

  this->qu = WQUF(n * n + 2);
  this->quT = WQUF(n * n + 2);

  for (int i = 0; i < n * n; i++)
  {
    this->state.push_back(false);
  }
}

void Percolation::setSize(int size)
{
  this->size = size;
}
int Percolation::getSize()
{
  return size;
}

/**
 * @return qu object
     */

WQUF Percolation::getQu()
{
  return qu;
}
std::vector<bool> Percolation::getState()
{
  return state;
}
void Percolation::setState(std::vector<bool> state)
{
  this->state = state;
}

 /**
     * Opens the site {@code index} if it is not open already
     * and try merge this element {@code index} with neighborhood
     * (up, down left, right)
     * 
     * @param index of the element.
     */
void Percolation::open(int index)
{
  state[index] = true;
  if (index < size * (size - 1))
  {
    if (isOpen(index + size))
    { // down

      qu.myUnion(index, index + size);
      quT.myUnion(index, index + size);
    }
  }
  if (index >= size)
  {
    if (isOpen(index - size))
    { // up

      qu.myUnion(index, index - size);
      quT.myUnion(index, index - size);
    }
  }
  if (index % size != size - 1)
  {
    if (isOpen(index + 1))
    { // right

      qu.myUnion(index, index + 1);
      quT.myUnion(index, index + 1);
    }
  }
  if (index % size != 0)
  {
    if (isOpen(index - 1))
    { // left

      qu.myUnion(index, index - 1);
      quT.myUnion(index, index - 1);
    }
  }
}
/**                                                                                                                                                                                 
     * Merge the opens site {@code index} with the 
     * virtual nodes {@code n*n}, {@code n*n+1} in 
     * qu and quT
     * (up, down left, right)                                                                                                                                                       
     *                                                                                                                                                                              
     * @param index of the element.                                                                                                                                                 
     */
void Percolation::virtualUnion(int index){
  if (index < size)
  {

    qu.myUnion(index, size * size);
  }
  if (index % size == 0)
  {

    quT.myUnion(index, size * size);
  }
  if (index >= size * (size - 1))
  {

    qu.myUnion(index, size * size + 1);
  }
  if (index % size == size - 1)
  {

    quT.myUnion(index, size * size + 1);
  }
}



void Percolation::setQu(WQUF qu)
{
  this->qu = qu;
}

/**                                                                                                                                                                                 
     * Check if the element {@code index} is open
     *                                                                                                                                                                              
     * @return true if it is open. False otherwise.
     */

bool Percolation::isOpen(int index)
{
  return state[index];
}

bool Percolation::isFull(int index)
{
  return !isOpen(index);
}

/**
     * returns the number of open sites.
     * @return number of elements in true sites 
     * in state vector.
     */

int Percolation::numberOfOpenSites()
{
  int count = 0;
  for (int i = 0; i < state.size(); i++)
  {
    if (state[i])
    {
      count++;
    }
  }
  return count;
}

/**
     * check if systmen percolate either from top to bottom or from left to right. 
     *
     * @return true if percolates, false otherwise.
     */

bool Percolation::percolates()
{
  return qu.find(size * size) == qu.find(size * size + 1) ||
         quT.find(size * size) == quT.find(size * size + 1);
}
