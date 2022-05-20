#include "../libs/Fill.h"
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    Fill fill;
    int L = 10; 
    for (int i = 0; i < 10; i++)
    {
        fill.percolate(i, 0.5, L);
        for (int jj = 0; jj < L; jj++)
        {
            std::cout << fill.getPercolation().getQu().find(jj) << " - ";
        }
        std::cout << std::endl;
    
    }
    


    return 0;
}
