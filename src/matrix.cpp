#include "matrix.h"

Matrix::Matrix(int rows, int cols, double* grid) {
        this->rows = rows;
        this->cols = cols;
        this->grid = grid;
}

int Matrix::getRows() const {
        return this->rows;
}

int Matrix::getCols() const {
        return this->cols;
}

void Matrix::print() {
        for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                        printf("%8.5f | ", at(i, j));
                }
                printf("\n");
        }
}

double Matrix::at(int row, int col) const {
        return grid[row * cols + col];
}

bool operator==(const Matrix& a, const Matrix& b) {
        if(a.getRows() != b.getRows() || a.getCols() != b.getCols()) {
                return false;
        }
        for(int rows = 0; rows < a.getRows(); rows++) {
                for(int cols = 0; cols < a.getCols(); cols++) {
                        if(a.at(rows, cols) != b.at(rows, cols)) return false;
                }
        }
        return true;
}

bool operator!=(const Matrix& a, const Matrix& b) {
        return !(a == b);
}
