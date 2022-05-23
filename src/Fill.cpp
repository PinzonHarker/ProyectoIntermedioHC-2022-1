#include "../libs/Fill.h"
#include "../libs/Percolation.h"
#include <random>
#include <string>
#include <iostream>


/**                                                                                                                                                                                 
 * Default constructo initializes the Fill object.
 * Create a Percolation object with argument {@code N}.
 *
 * @throws IllegalArgumentException if {@code N < 0} 
 */

Fill::Fill(int N)
{
  percolation = Percolation(N);
}


/**
 * Convert to string the {@code matrix} vector 
 * 
 * @params matrix representing sytem.
 * @return the matrix vector with string
 * to let visualize a matrix.
 */

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

/**
 * Fill the {@code matrix} vector with open elements, through
 * a probalility {@code p} with uniform-real distribution and seed, also
 * fill the vectors of boundarie rowTop, rowBottom., colLeft, colRight, 
 * and finally initailize the vector clusters.  
 *
 * @params seed semilla of uniform-real distribution.
 * @params p probabily to open site.
 * @params n number of rows or columns
 * throws IllegalArgumentException unles
 * {@code 0 <= p < n*n-1};
 */

void Fill::fillAndUnion(int seed, double p, int n)
{

  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(0, 1);
  for (int i = 0; i < n*n; ++i)
  {
    float gen2 = dis(gen);
    if (gen2 <= p)
    {
      
      matrix.push_back(1);
      percolation.open(i);
      	
      // if(i<n) rowTop.push_back(i);
      //if(i%n == 0) colLeft.push_back(i);
      //if(i%n == n-1) colRight.push_back(i);
      //if(i>= n*(n-1)) rowBottom.push_back(i);
      
    }
    else
    {
      matrix.push_back(0);
    }
  }

  //clusters = percolation.getQu().getSize();
  
}

/**                                                                                                                                                                                 
 * Unionl the vectors of boundarie rowTop, rowBottom., colLeft, colRight,                                                                                                           
 * whit virtuals elements {@code n*n} and {@code n*n+1}
 */                                                                                                                                                                                  


/*void Fill::virtualUnion(){
  
  
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
  
  }*/

/**                                                                                                                                                                                 
 * Fill the element {@code i} with parent or root to show 
 * the percolant clusters in the matrix vector 
 */

void Fill:: paintClusters(){
  for(int i =0; i<matrix.size(); i++){
    if(matrix[i] == 1){     
      matrix[i] = percolation.getQu().find(i);
    }
  }
}
/**                                                                                                                                                                                 
 * If the system percolate return the size of 
 * the greatest percolate cluster of the matrix vector 
 * and 1 otherwise  
 *
 * @return size greatest cluster if system percolate and 1 otherwise   
*/

/*int Fill::findGreatestCluster(){

  int greatest=0;
  for(int cluster:clusters){
    //std::cout<<cluster<<" ";
    if(cluster>greatest){
      greatest = cluster;
    }
  }
  //std::cout<<std::endl;

  return greatest;
  }*/

/**                                                                                                                                                                                 
 * check si the matrix vector percolate and call
 * fillAndUnion,  paintClusters, virtualUnion methods.
 *                                                                                                                                                                                  
 * @params seed semilla of uniform-real distribution.
 * argument fillAndUnion method .
 * @params p probabily to open site argument fillAndUnion 
 * method.                                                                                                                                                  
 * @params n number of rows or columns 
 * argument fillAndUnion method  
 * @return true 
 * @throws IllegalArgumentException unles                                                                                                                                           
 * {@code 0 <= p < n*n-1};
                                                                                                                                                          
 */
bool Fill::percolate(int seed, double p, int N)
{
  fillAndUnion(seed, p, N);
  paintClusters();
  // virtualUnion();
  return percolation.percolates();
}
/**                                                                                                                                                                                 
 * Return {@code matrix} vector 
 *                                                                                                                                                                                  
 * @return {@code matrix} vector.
*/
std::vector<int> Fill::getMatrix()
{
  return matrix;
}
/**                                                                                                                                                                                 
 * return the Percolation object.
 *                                                                                                                                                                                  
 * @return Percolation object.                                                                                                                                                    
*/
Percolation Fill::getPercolation()
{
  return percolation;
}
