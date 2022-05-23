#pragma once

#include <vector>

class WQUF
{
private:
  std::vector<int> parent;
  std::vector<int> size;
  std::vector<int> rowTop;
  std::vector<int> rowBottom;
  std::vector<int> colLeft;
  std::vector<int> colRight;
  int count;
  void validate(int p);
  short isInBoundary(int p);
  void putInBoundary(short, int, int);
  void pathCompression(int, int);
public:
  
  int getCount();
  WQUF ();
  WQUF(int n);
  int find(int p);
  void myUnion(int p, int q);
  std::vector<int> getSize();
  std::vector<int> getRowTop();
  std::vector<int> getRowBottom();
  std::vector<int> getColLeft();
  std::vector<int> getColRight();
};
