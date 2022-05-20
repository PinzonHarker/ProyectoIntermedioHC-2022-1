#pragma once

#include "percolation.h"
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
  bool percolate(int seed, double probability, int L);
  std::string toString(std::vector<int> vector);  
  void paintClusters();
  int findGreatestCluster();
};
