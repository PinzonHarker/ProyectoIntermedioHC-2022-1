#pragma once

#include <vector>

class WQUF
{
private:
  std::vector<int> parent;
  std::vector<int> size;
  int count;
  void validate(int p);

public:
  WQUF(int n);
  int getCount();
  int find(int p);
  void myUnion(int p, int q);
  
};
