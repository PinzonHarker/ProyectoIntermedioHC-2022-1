#pragma once

#include "Percolation.h"
#include <vector>
#include <string>

class Fill
{

private:
  std::vector<bool> matrix;
  Percolation percolation;
  void fill(int, double, int);

public:
  std::vector<bool> getMatrix();
  Percolation getPercolation();
  bool percolate(int, double, int);
  std::string toString(std::vector<bool> vector);
  
};
