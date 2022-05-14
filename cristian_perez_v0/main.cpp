#include <iostream>
#include <vector>
#include "percolation.h"
#include <random>

int main(int agrc,char *argv[]){

  //std::vector<int> grid(N*N);

  std::cout<<argv[1]<<" "<<argv[2]<<" "<<argv[3]<<std::endl;
  
  int seed = std::atoi("2");
  float p = std::atof("0.5");
  int N = std::atoi("20");
  
  Percolation percolation = Percolation(N);
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  for(int i = 0; i < N*N; ++i) {
    //for(int j = 0; j < N; ++j) {
      float gen2 = dis(gen);
      if(gen2<=p){
	percolation.open(i);
	//grid[n] = 1;
	//}
    }
  }

  
  
  //int n = 4;
  //Percolation p = Percolation(n);
  // p.open(0, 1);
  //p.open(1, 1);
  //p.open(2, 1);
  
  for (int i = 0; i < N * N + 2; i++){
    std::cout<<percolation.getQu().find(i)<<" ";;
  }
  std::cout<<"Sitios libres: "<<percolation.numberOfOpenSites()<<std::endl;
  std::cout<<"Percola: "<<percolation.percolates()<<std::endl;

  
  return 0;
}
