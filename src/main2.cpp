#include "../libs/Fill.h"
#include "../libs/Stats.h"
#include "Stats.cpp"
#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <string>

int main(int argc, char **argv)
{
    int seed = std::atoi(argv[1]);
    float p = std::atof(argv[2]);
    int L = std::atoi(argv[3]); //L es el tamaño de la matriz percolante.
    int M = 10; // Número de muestra, entre más mejor.
    int k; // Contador de percolaciones. Al menos un cluster percolante.

    Fill fill;
    std::vector<double> cluster(M);
    std::vector<double> probability(M);

    // Recorrer desde 1 a M
    for (int i = 1; i < M; i++)
    {
        fill.percolate(i, p, L);
        cluster[i] = fill.findGreatestCluster();
    }

    // Probabilidad de cada matriz
    for (int i = 0; i < M; i++)
    {
        // Cuenta que exista un cluster 
        for (int j = 0; j < M; j++)
        {
            k = 0;
            fill.percolate(j, p, L);
            if (fill.findGreatestCluster() > 0)
            {
                k = k + 1;
            }
        }
        probability[i] = k / 10.0;
    }

    std::cout << mean(cluster) << "\t" << desv(cluster) << "\t" << mean(probability) << "\t" << desv(probability) << std::endl;
}

