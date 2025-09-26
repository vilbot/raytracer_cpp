#include "matrix.h"

Matrix::Matrix(int rows, int cols, double* grid) {
        this->rows = rows;
        this->cols = cols;
        this->grid = new double[rows * cols];
}

void Matrix::print() {
        for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                        printf("%8.5f | ", at(i, j));
                }
        }
}

double Matrix::at(int row, int col) {
        return grid[row * cols + col];
}
