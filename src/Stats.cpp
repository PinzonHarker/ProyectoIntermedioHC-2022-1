#include "../libs/Stats.h"
#include <vector>
#include <numeric>
#include <cmath>

double mean(std::vector<double> &data)
{
  if (data.size() == 0)
    return 0.0;
  return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

double desv(std::vector<double> &data)
{
  double sum = 0;
  double average = mean(data);
  int i;
  double size = data.size();
  for (i = 0; i < size; i++)
  {
    sum += data[i] * data[i] - 2 * data[i] * average + average * average;
  }
  double sigma;
  sigma = std::sqrt(sum / size);
  return sigma;
}
