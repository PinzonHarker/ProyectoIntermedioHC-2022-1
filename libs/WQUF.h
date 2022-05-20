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
  
  int getCount();
  WQUF ();
  WQUF(int n);
  int find(int p);
  void myUnion(int p, int q);
  std::vector<int> getSize();
};
