
#include <random>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "fill_vector.h"

std::vector<int> fillVector(int N, int seed, double p){
  std::vector<int> grid(N*N);
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  for(int n = 0; n < N*N; ++n) {
    float gen2 = dis(gen);
    if(gen2<=p){                                                                                                                                                                               
      grid[n] = 1;
    }else{                                                                                                                                                                               
      grid[n] = 0;
    }
                                                                                                                                                            
  }
  return grid;
}

std::string toString(std::vector<int> grid){
  std::string matrix ="";
  for(int i=0; i<sqrt(grid.size()); i++){
    for(int j = 0; j<sqrt(grid.size()); j++){ 
      std::stringstream stream;
      matrix.append(std::to_string(grid.at(j*i + j)));
      matrix.append(" ");
    }
    matrix.append("\n"); 
  }
  return matrix;
}
