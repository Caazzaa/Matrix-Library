#ifndef CAZLIB_H

#define CAZLIB_H

#include <stdio.h>

typedef struct {
    size_t rows;
    size_t cols;
    double **data; //pointer to 2D array of matrix values
} caz_mat;

typedef caz_mat* Matrix;

Matrix newCazMatrix(size_t rows, size_t cols);
void freeCazMatrix(Matrix *mat);
void PrintMatrix(Matrix mat);

#endif // CAZLIB_H