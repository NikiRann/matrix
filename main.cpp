#include <iostream>
#include <cmath>
#include <Matrix.h>


int solveBaseMatrix(Matrix matrix)
{
    int delta;
    delta = matrix.numbers[0][0] * matrix.numbers[1][1] * matrix.numbers[2][2] + matrix.numbers[0][1] * matrix.numbers[1][2] * matrix.numbers[2][0] + matrix.numbers[1][0] * matrix.numbers[2][1] * matrix.numbers[0][2]
    - (matrix.numbers[0][2] * matrix.numbers[1][1] * matrix.numbers[2][0] + matrix.numbers[0][0] * matrix.numbers[1][2] * matrix.numbers[2][1] + matrix.numbers[0][1] * matrix.numbers[1][0] * matrix.numbers[2][2]);
    return delta;
}
int solveComplexMatrix(Matrix matrix)
{
    if (matrix.getSize() == 3)
        return solveBaseMatrix(matrix);
    int sum = 0;
    for (int i = 0; i < matrix.getSize(); i ++)
    {

        std::vector< std::vector <int> > newMatrix;
        for (int k = 0; k < matrix.getSize(); k ++ )
        {
            std::vector <int> pusherV;
            for (int p = 1;p < matrix.getSize(); p ++)
            {
                int pusher;
                pusher = matrix.numbers[p][k];
                pusherV.push_back(pusher);

            }
            if (i != k)
                newMatrix.push_back(pusherV);
            delete &pusherV;
        }
        //std::cout << i << "\n";
        Matrix m(newMatrix, matrix.getSize() - 1);
        sum += matrix.numbers[0][i] * pow((-1), i) * solveComplexMatrix(m);
    }
    return sum;
}
int main()
{
    Matrix testMatrix(5);

    testMatrix.Read();
    std::cout << solveComplexMatrix(testMatrix) << "\n";
    return 0;
}
