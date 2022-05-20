#include "../libs/Fill.h"
#include "../libs/Percolation.h"
#include <random>
#include <string>
#include <iostream>



std::string Fill::toString(std::vector<int> matrix)
{
  std::string sMatrix = "";
  for (int i = 0; i < sqrt(matrix.size()); i++)
  {
    for (int j = 0; j < sqrt(matrix.size()); j++)
    {
      sMatrix.append(std::to_string(matrix.at(i * sqrt(matrix.size()) + j)));
      sMatrix.append("\t");
    }
    sMatrix.append("\n");
  }
  return sMatrix;
}

Fill::Fill(int N)
{
  percolation = Percolation(N);
}

void Fill::fillAndUnion(int seed, double p, int N)
{

  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  for (int i = 0; i < N * N; ++i)
  {
    float gen2 = dis(gen);
    if (gen2 <= p)
    {
      
      matrix.push_back(1);
      percolation.open(i);
      	
      if(i<N) rowTop.push_back(i);
      if(i%N == 0) colLeft.push_back(i);
      if(i%N == N-1) colRight.push_back(i);
      if(i>= N*(N-1)) rowBottom.push_back(i);
      
    }
    else
    {
      matrix.push_back(0);
    }
  }

  clusters = percolation.getQu().getSize();
  
}

void Fill::virtualUnion(){
  
  
  for(int pos:rowTop){
    percolation.virtualUnion(pos);
  }
  for(int pos:rowBottom){
    percolation.virtualUnion(pos);
  }
  for(int pos:colLeft){
    percolation.virtualUnion(pos);
  }
  for(int pos:colRight){
    percolation.virtualUnion(pos);
  }
  
}

void Fill:: paintClusters(){
  for(int i =0; i<matrix.size(); i++){
    if(matrix[i] == 1){     
      matrix[i] = percolation.getQu().find(i);
    }
  }
}

int Fill::findGreatestCluster(){

  int greatest=0;
  for(int cluster:clusters){
    std::cout<<cluster<<" ";
    if(cluster>greatest){
      greatest = cluster;
    }
  }
  std::cout<<std::endl;

  return greatest;
}

bool Fill::percolate(int seed, double p, int N)
{
  fillAndUnion(seed, p, N);
  paintClusters();
  virtualUnion();
  return percolation.percolates();
}

std::vector<int> Fill::getMatrix()
{
  return matrix;
}
Percolation Fill::getPercolation()
{
  return percolation;
}
