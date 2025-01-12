#ifndef CAZLIB_H

#define CAZLIB_H

#include <stdio.h>
#include <stddef.h>

typedef struct {
    size_t rows;
    size_t cols;
    double **data; //pointer to 2D array of matrix values
} caz_mat;

typedef caz_mat* Matrix;

/* 
    Create Matrices
*/
Matrix newCazMatrix(size_t rows, size_t cols);
void freeCazMatrix(Matrix *mat);
Matrix newIdentityMatrix(size_t size);

/*
    Print Matrices
*/
void PrintMatrix(Matrix mat);

float square_root(float number);
int pow(int base, int exp);

/*
    Basic Matrix Operations
*/
Matrix addMatrix(Matrix mat1, Matrix mat2);
Matrix subtractMatrix(Matrix mat1, Matrix mat2);
Matrix scalarMultiplication(double scalar, Matrix mat);
Matrix scalarDivision(double scalar, Matrix mat);
double vectorMagnitude(Matrix vector);
Matrix unitVector(Matrix vector);


/*
    Advanced Matrix Operations
*/
Matrix dotProduct(Matrix mat1, Matrix mat2);

#endif // CAZLIB_H