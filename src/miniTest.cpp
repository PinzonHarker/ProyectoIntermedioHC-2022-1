#include "../libs/WQUF.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    int rows = 9;
    int listUnions[9][2] = {
        {4, 3}, // 0
        {3, 8}, // 1
        {6, 5}, // 2
        {9, 4}, // 3
        {2, 1}, // 4
        {5, 0}, // 5
        {7, 2}, // 6
        {6, 1}, // 7
        {7, 3}};
    WQUF test = WQUF(10);
    for (int i = 0; i < rows; i++)
    {
        test.myUnion(listUnions[i][0], listUnions[i][1]);
        for (int j = 0; j < 10; j++)
        {
            std::cout << test.find(j) << " ";
        }
        std::cout << "\t c= " << i << std::endl;
    }

    return 0;
}
