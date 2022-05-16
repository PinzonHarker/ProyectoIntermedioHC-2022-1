#pragma once
#include <vector>
#include "percolation.h"
#include <string>

class Fill{

private:

  std::vector<bool> matrix;
  Percolation percolation;
  void fill(int, double, int);

public:
  
  bool percolate(int, double, int);
  std::string toString(std::vector<bool> vector);
  std::vector<bool> getMatrix();
  Percolation getPercolation();

};
