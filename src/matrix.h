#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

class Matrix {
private:
        int rows, cols;

public:
        double* grid;
        Matrix(int rows, int cols, double* grid);
        int getRows() const;
        int getCols() const;
        void print();
        double at(int row, int col) const;
};

bool operator==(const Matrix& a, const Matrix& b);
bool operator!=(const Matrix& a, const Matrix& b);

#endif
