#include "cazlib.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Basic Creation, Deletion and Printing of a Matrix
*/
Matrix newCazMatrix(size_t rows, size_t cols) {
    Matrix mat = (Matrix)malloc(sizeof(caz_mat));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double**)malloc(rows * sizeof(double*));
    for (size_t i = 0; i < rows; i++) {
        mat->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return mat;
}

Matrix newIdentityMatrix(size_t size) {
    Matrix mat = newCazMatrix(size, size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            mat->data[i][j] = (i == j) ? 1 : 0;
        }
    }
    return mat;
}

void freeCazMatrix(Matrix *mat) {
    if (!(*mat == NULL)) {
        for (size_t i = 0; i < (*mat)->rows; i++) {
            free((*mat)->data[i]);
        }
        free((*mat)->data);
        free(*mat);
        *mat = NULL;
    }
}

void PrintMatrix(Matrix mat) {
    if (!(mat == NULL)) {
        for (int i = 0; i < mat->rows; i++) {
            for (int j = 0; j < mat->cols; j++)
                printf("%0.3f ", mat->data[i][j]);
            printf("\n");
        }
    }
}


/*
    Custom Math Functions
*/
float square_root(float number) { 
    float temp, sqrt;

    sqrt = number / 2;
    temp = 0;

    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( number/temp + temp) / 2;
    }
    return sqrt;
} 

int pow(int base, int exp){
      if(exp < 0)
        return -1;

        int result = 1;
        while (exp){
            if (exp & 1)
                result *= base;
            exp >>= 1;
            base *= base;
        }

        return result;
    }


/*
    First Basic Matrix Operations
*/
Matrix addMatrix(Matrix mat1, Matrix mat2){
    if(mat1 -> rows != mat2 -> rows || mat1 -> cols != mat2 -> cols){
        printf("Error: Matrices must have the same dimensions to add them.\n");
        return 0;
    }
    Matrix result = newCazMatrix(mat1 -> rows, mat1 -> cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++)
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
    }
    return result;
}

Matrix subtractMatrix(Matrix mat1, Matrix mat2){
    if(mat1 -> rows != mat2 -> rows || mat1 -> cols != mat2 -> cols){
        printf("Error: Matrices must have the same dimensions to subtract them.\n");
        return 0;
    }
    Matrix result = newCazMatrix(mat1 -> rows, mat1 -> cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++)
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
    }
    return result;
}

Matrix scalarMultiplication(double scalar, Matrix mat){
    Matrix result = newCazMatrix(mat->rows, mat->cols);
    for(int i = 0; i < mat -> rows; i++){
        for(int j = 0; j < mat->cols; j++)
            result->data[i][j] = scalar * mat->data[i][j];
    }
    return result;
}

Matrix scalarDivision(double scalar, Matrix mat){
    Matrix result = newCazMatrix(mat->rows, mat->cols);
    for(int i = 0; i < mat -> rows; i++){
        for(int j = 0; j < mat->cols; j++)
            result->data[i][j] = mat->data[i][j] / scalar;
    }
    return result;
}

double vectorMagnitude(Matrix vector){
    double result = 0;
    for(int i = 0; i < vector -> rows; i++){
        for(int j = 0; j < vector->cols; j++)
          result += pow(vector->data[i][j], 2);
    }
    result = square_root(result);
    return result;
}

Matrix unitVector(Matrix vector){
    double norm = vectorMagnitude(vector);
    printf("%0.3f\n", norm);
    Matrix result = newCazMatrix(vector -> rows, vector -> cols);
    result = scalarDivision(norm, vector);
    return result;
}

/* 
    Dot and Cross Product
*/
Matrix dotProduct(Matrix mat1, Matrix mat2){
    // Check if the number of columns in the first matrix is equal to the number of rows in the second matrix
    if(mat1 -> cols != mat2 -> rows){
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 0;
    }
    Matrix result = newCazMatrix(mat1 -> rows, mat2 -> cols);
    for (int i = 0; i < mat1->rows; i++) {
        for(int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = 0;
            for(int k = 0; k < mat1->cols; k++)
                result->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
                printf("%0.3f ", result->data[i][j]);
        }
    }
    return result;
}