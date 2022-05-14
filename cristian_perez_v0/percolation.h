#pragma once
#include <vector>
#include "WeightedQuickUnionUF.h"

class Percolation{

private:

  bool begin = true;
  bool end = true;
  std::vector<bool> state;//estados 
  WeightedQuickUnionUF qu;//algoritmo find-union
  int size;

public:
  
  Percolation(int n);//metodo constructor, inicializa mis varibles 
  void setSize(int n);//
  int getSize();
  WeightedQuickUnionUF getQu();
  void setQu(WeightedQuickUnionUF qu);
  std::vector<bool> getState();
  void setState(std::vector<bool> state);
  void open(int index);
  bool isOpen(int index);
  bool isFull(int index);
  int numberOfOpenSites();
  bool percolates();

};

