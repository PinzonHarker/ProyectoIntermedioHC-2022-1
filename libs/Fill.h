#pragma once

#include "Percolation.h"
#include <vector>
#include <string>

class Fill
{

private:
  std::vector<int> matrix;
  std::vector<int> clusters;
  Percolation percolation;
  void fillAndUnion(int, double, int);

public:
  std::vector<int> getMatrix();
  Percolation getPercolation();
  bool percolate(int, double, int);
  std::string toString(std::vector<int> vector);  
  void paintClusters();
  int findGreatestCluster();
};
