#include "../libs/WQUF.h"
#include <vector>
#include <iostream>

WQUF::WQUF() {}

/**
     * Initializes an the weigthed quick union-find data structure with
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
  }
}

int WQUF::getCount()
{
  return count;
}

int WQUF::find(int p)
{
  validate(p);
  int root = p;
  while (root != parent[root])
    root = parent[root];
  while (p != root)
  {
    int newp = parent[p];
    parent[p] = root;
    p = newp;
  }
  return p;
}
void WQUF::validate(int p)
{
  int n = parent.size();
  if (p < 0 || p >= n)
  {
    std::cout<<"The value must into the range."<<" "<<p<<std::endl;
    throw std::invalid_argument("The value must into the range.");
  }
}
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
