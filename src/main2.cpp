#include "../libs/Fill.h"
#include "mean"
#include "desv"
#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <string>

int main(int argc, char ** argv){
    int seed = std::atoi(argv[1]);
    float p = std::atof(argv[2]);
    int N = std::atoi(argv[3]);
    std::vector<double> cluster (10);
    std::vector<double> probability (10);

    for(int i=0; i<10; i++){
        fill.precolate(seed, p, N);
        cluster[i]=findGreatestCluster(N,p);
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            int k=0;
            fill.precolate(seed, p, N);
            if(fill.findGreatestCluster()>0){k=k+1;}
        }
        probability[i]=k/10.0;
    }

  std::cout << mean(cluster)<<"\t" << desv(cluster) <<"\t"<<mean(probability)<<"\t"<<desv(probability)<<"\n"; 
}
