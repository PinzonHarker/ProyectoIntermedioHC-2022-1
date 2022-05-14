#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "fill_vector.h"
void printMatriz(std::vector<int> grid);

int main(int agrc,char *argv[])
{
  
  int seed = std::atoi(argv[1]);
  float p = std::atof(argv[2]);
  int N = std::atoi(argv[3]);
  
   std::vector<int> grid(N*N);
   grid = fillVector(N,seed, p);
  std::string matriz =  toString(grid);
  /* std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  for(int n = 0; n < N*N; ++n) {
    float gen2 = dis(gen);
    if(gen2<=p){
      //std::cout<<1<<"  ";
      grid[n] = 1;
    }else{
      // std::cout<<0<<"  ";
      grid[n] = 0;
    }
    // std::cout<<" "<<gen2<<" "<<p<< std::endl;
    }*/
  std::cout<<matriz<<std::endl;
  //printMatriz(grid);
  return 0;
}

/*void printMatriz(std::vector<int> grid){
  for(int i=0; i<sqrt(grid.size()); i++){
    for(int j = 0; j<sqrt(grid.size()); j++){
      std::cout<<grid.at(j*i + j)<<" ";
      
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
  }*/

