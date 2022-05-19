#include "../libs/Fill.h"
#include <iostream>
#include <string>

int main(int agrc, char *argv[])
{

  // std::vector<int> grid(N*N);

  std::cout << argv[1] << " " << argv[2] << " " << argv[3] << std::endl;

  int seed = std::atoi(argv[1]);
  float p = std::atof(argv[2]);
  int N = std::atoi(argv[3]);

  Fill fill;
  
  std::cout << "Percola: " << fill.percolate(seed, p, N) << std::endl;
  std::cout << "Sitios libres: " << fill.getPercolation().numberOfOpenSites() << std::endl;
  std::cout<< "El mayor cluster percolanter tiene tamaño "<<fill.findGreatestCluster()<<std::endl;
  std::cout << fill.toString(fill.getMatrix()) << std::endl;
  std::cout << std::endl;

  return 0;
}
