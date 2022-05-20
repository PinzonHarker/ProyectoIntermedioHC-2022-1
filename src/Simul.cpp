#include "../libs/Fill.h"
#include <iostream>
#include <string>

Fill fill;
std::string decidePercolation(int seed, float p, int L);
int main(int agrc, char *argv[])
{

  int seed = std::atoi(argv[1]);
  float p = std::atof(argv[2]);
  int L = std::atoi(argv[3]);

  std::cout << "1.Seed = {" << seed << "} 2.Probabilidad = {" << p << "} 3.Tamaño de la matriz {" << L << "} " << std::endl;

  std::cout << "Percola: " << decidePercolation(seed, p, L) << std::endl;
  std::cout << "Sitios libres: " << fill.getPercolation().numberOfOpenSites() << std::endl;
  std::cout << "El mayor cluster percolanter tiene tamaño " << fill.findGreatestCluster() << std::endl;
  std::cout << fill.toString(fill.getMatrix()) << std::endl;
  std::cout << std::endl;

  return 0;
}

std::string decidePercolation(int seed, float p, int L)
{
  if (fill.percolate(seed, p, L))
  {
    return "YES";
  }
  else
  {
    return "NO";
  }
}