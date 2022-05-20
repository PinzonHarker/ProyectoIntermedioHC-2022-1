#include "../libs/Fill.h"
#include "../libs/Stats.h"
#include "Stats.cpp"
#include <iostream>
#include <vector>

/*
    El objetivo es variar mi p y sacar los resultados
    en .dat donde nos permita cambiar de L para cada .dat y
    conocer un como afecta esta variación
*/
int main(int argc, char const *argv[])
{
    Fill fill;
    int seed = std::atoi(argv[1]); // Seed solamente de inicio.
    int M = std::atoi(argv[2]);    // Número de muestra de matrices para hallar la probabilidad, entre más mejor.
    int L = std::atoi(argv[3]);    // L es el tamaño de la matriz percolante.
    double p = 0;                  // Probabilidad, la variaremos

    double step = 1.0/1000;
    double limit = 1.0 / step;
    double count = 0.0;

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    std::vector<double> probability; // Probabilidad de percolación respecto cada elemento

    // Variaremos p para mostrar un rango de valores donde es percolante y donde no
    for (int ii = 0; ii < limit; ii++)
    {
        p += step;
        for (int jj = 0; jj < M; jj++)
        {
            seed ++;
            if (fill.percolate(seed, p, L))
                count++;
        }
        std::cout << p << "\t" << count/M << std::endl;
        count = 0;
    }

    return EXIT_SUCCESS;
}
