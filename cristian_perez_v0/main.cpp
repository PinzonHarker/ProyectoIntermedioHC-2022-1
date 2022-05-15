#include <iostream>
#include <vector>
#include "percolation.h"
#include <random>
#include "fill_vector.h"
#include <string>
#include <sstream>

int main(int agrc,char *argv[]){

  //std::vector<int> grid(N*N);

  std::cout<<argv[1]<<" "<<argv[2]<<" "<<argv[3]<<std::endl;
  
  int seed = std::atoi(argv[1]);
  float p = std::atof(argv[2]);
  int N = std::atoi(argv[3]);
  std::vector<int> matriz;
  
  Percolation percolation = Percolation(N);
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  for(int i = 0; i < N*N; ++i) {
    //for(int j = 0; j < N; ++j) {
      float gen2 = dis(gen);
      if(gen2<=p){
	matriz.push_back(1);
	percolation.open(i);
	//grid[n] = 1;
	//}
      }else{
	matriz.push_back(0);
      }
  }

 
  toStringMatriz(matriz);
  
  //int n = 4;
  //Percolation p = Percolation(n);
  // p.open(0, 1);
  //p.open(1, 1);
  //p.open(2, 1);
  
  /*for (int i = 0; i < N * N + 2; i++){
    std::cout<<percolation.getQu().find(i)<<" ";;
    }*/
  std::cout<<"Sitios libres: "<<percolation.numberOfOpenSites()<<std::endl;
  std::cout<<"Percola: "<<percolation.percolates()<<std::endl;
  std::cout<<toStringMatriz(matriz)<<std::endl;
  std::cout<<std::endl;
  
  return 0;
}
