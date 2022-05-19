#include "../libs/Fill.h"
#include "../libs/Percolation.h"
#include <random>
#include <string>

std::string Fill::toString(std::vector<bool> matrix)
{
  std::string sMatrix = "";
  for (int i = 0; i < sqrt(matrix.size()); i++)
  {
    for (int j = 0; j < sqrt(matrix.size()); j++)
    {
      sMatrix.append(std::to_string(matrix.at(i * sqrt(matrix.size()) + j)));
      sMatrix.append(" ");
    }
    sMatrix.append("\n");
  }
  return sMatrix;
}

void Fill::fill(int seed, double p, int N)
{
  Percolation percolation = Percolation(N);
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  for (int i = 0; i < N * N; ++i)
  {
    float gen2 = dis(gen);
    if (gen2 <= p)
    {
      matrix.push_back(1);
      percolation.open(i);
    }
    else
    {
      matrix.push_back(0);
    }
  }
}

bool Fill::percolate(int seed, double p, int N)
{
  fill(seed, p, N);
  return percolation.percolates();
}

std::vector<bool> Fill::getMatrix()
{
  return matrix;
}
Percolation Fill::getPercolation()
{
  return percolation;
}
