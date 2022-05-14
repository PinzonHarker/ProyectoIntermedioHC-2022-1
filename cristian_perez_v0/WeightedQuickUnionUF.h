#pragma once
#include <vector>

class WeightedQuickUnionUF{
private:

  std::vector<int> parent;
  std::vector<int> size;
  int count;
  void validate(int p);

public:
  WeightedQuickUnionUF();
  WeightedQuickUnionUF(int n);
  int getCount();
  int find(int p);
  void myUnion(int p, int q);

}; 
