#pragma once

#include "percolation.h"
#include <vector>
#include <string>

class Fill
{

private:
  std::vector<int> matrix;
  Percolation percolation;
  void fill(int, double, int);

public:
  std::vector<int> getMatrix();
  Percolation getPercolation();
  bool percolate(int, double, int);
  std::string toString(std::vector<int> vector);  
  void paintClusters();
};
