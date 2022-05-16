#pragma once

#include "WQUF.h"
#include <vector>

class Percolation
{

private:
  bool begin = true;
  bool end = true;
  std::vector<bool> state; // estados
  WQUF qu; // algoritmo find-union
  WQUF quT;
  int size;

public:
  Percolation();
  Percolation(int n); // metodo constructor, inicializa mis varibles
  void setSize(int n);
  int getSize();
  WQUF getQu();
  void setQu(WQUF qu);
  void setQuT(WQUF quT);
  std::vector<bool> getState();
  void setState(std::vector<bool> state);
  void open(int index);
  bool isOpen(int index);
  bool isFull(int index);
  int numberOfOpenSites();
  bool percolates();
  void fill(int seed, double p, int n);
};
