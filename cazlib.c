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