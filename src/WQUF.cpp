#include "../libs/WQUF.h"
#include <vector>
#include <iostream>


WQUF::WQUF(int n)
{
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
  while (p != parent[p])
    p = parent[p];
  return p;
}
void WQUF::validate(int p)
{
  int n = parent.size();
  if (p < 0 || p >= n)
  {
    // throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n-1));
    std::cout << "Exception xd"
              << " " << p << std::endl;
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
