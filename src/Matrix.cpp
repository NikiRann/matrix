#include "Matrix.h"
#include <cmath>
#include <vector>
#include <iostream>

Matrix::Matrix(int _size)
{
    size = _size;
}
Matrix::Matrix(std::vector< std::vector <int> > values, int n)
{
    size = n;
    numbers = values;
}
int Matrix::getSize()
{
    return size;
}

void Matrix::Read()
{

    for (int y = 0; y < size; y ++ )
    {
        std::vector <int> pusherV;
        for (int x = 0; x < size; x ++)
        {
            int pusher;
            std::cin >> pusher;
            pusherV.push_back(pusher);

        }
        this -> numbers.push_back(pusherV);
        delete &pusherV;
    }
    std::cout << "Finished \n";
}
