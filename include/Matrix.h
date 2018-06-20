#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix
{
    public:
        std::vector< std::vector <int> > numbers;
        Matrix(int);
        Matrix(std::vector< std::vector <int> >, int);
        void Read();
        int getSize();

    private:
        int size;
        int delta;

};

#endif // MATRIX_H
