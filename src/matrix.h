#ifndef MATRIX_H
#define MATRIX_H

#include "includes.h"

class Matrix {
public:
        int rows, cols;
        double* grid;

        Matrix(int rows, int cols, double* grid);
        void print();
        double at(int row, int col);
};

#endif
