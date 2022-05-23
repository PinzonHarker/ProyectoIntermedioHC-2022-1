#include "../libs/WQUF.h"
#include <vector>
#include <iostream>

/**
 * Default constructor don't Initializes the weigthed quick union-find
 */

WQUF::WQUF() {}

/**
     * Initializes an the weigthed quick union-find with
     * {@code n} elements {@code 0} through {@code n-1}. 
     * Initially, each element is in its own set.
     *
     * @param  n the number of elements
     * @throws IllegalArgumentException if {@code n < 0}
     */

WQUF::WQUF(int n)
{
  if(n < 0){
    std::cout<<"The value must into the range."<<" "<<n<<std::endl;
    throw std::invalid_argument("The value must into the range.");
  }
  count = n;
  for (int i = 0; i < n; i++)
  {
    parent.push_back(i);
    size.push_back(1);
    rowTop.push_back(0);
    rowBottom.push_back(0);
    colLeft.push_back(0);
    colRight.push_back(0);
  }
}

int WQUF::getCount()
{
  return count;
}
/**
     * Returns the root or parent element of the set containing element {@code p}.
     *
     * @param  p an element
     * @return the root or parent element of the set containing {@code p}
     * @throws IllegalArgumentException unless {@code 0 <= p < n}
     */
int WQUF::find(int p)
{
  validate(p);
  int root = p;
  while (root != parent[root])
    root = parent[root];
  /*while (p != root)
  {
    int newp = parent[p];
    parent[p] = root;
    p = newp;
    }*/
  return p;
}

void WQUF::pathCompression(int p, int root){
  while (p != root)
  {
    int newp = parent[p];
    parent[p] = root;
    short boudary = isInBoundary(p);
    if(boundary<4){
      putInBoundary(boundary, root, index);
    }
    p = newp;
  }
}

/**
     * Valide if {@code 0 <= p < n} otherwise throw exception
     *
     * @param  p an element
     * @throws IllegalArgumentException unless {@code 0 <= p < n}
     */
void WQUF::validate(int p)
{
  int n = parent.size();
  if (p < 0 || p >= n)
  {
    std::cout<<"The value must into the range."<<" "<<p<<std::endl;
    throw std::invalid_argument("The value must into the range.");
  }
}
/**
     * Merges the set containing element {@code p} with the 
     * the set containing element {@code q}.
     *
     * @param  p one element
     * @param  q the other element
     * @throws IllegalArgumentException unless
     *         both {@code 0 <= p < n} and {@code 0 <= q < n}
     */
void WQUF::myUnion(int p, int q)
{
  
  int rootP = find(p);
  int rootQ = find(q);
  if (rootP == rootQ)
    return;
  // make smaller root point to larger one
  if (size[rootP] < size[rootQ])
  {
    parent[rootP] = rootQ;
    size[rootQ] += size[rootP];
  }
  else
  {
    parent[rootQ] = rootP;
    size[rootP] += size[rootQ];
  }
  count--;
}
std::vector<int> WQUF::getSize(){
  return size;
}

short WQUF::isInBoundary(){

  if(i<n) return 0; 
  if(i%n == 0) return 1;
  if(i%n == n-1) return 2; 
  if(i>= n*(n-1)) return 3;
  return 4;
}

void WQUF::putInBoundary(short boundary, int root, int index){

  switch(boundary){
  case 0: rowTop[index] = root;
  case 1: colLeft[index] = root;
  case 2: colRight[index] = root;
  case 3: rowBottom[index] = root;
  }

}
