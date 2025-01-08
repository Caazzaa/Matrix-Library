#include <stdio.h>
#include <stdlib.h>
#include "cazlib.h"

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
