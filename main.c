#include "cazlib.h"

void FillMatrix(Matrix mat){
    for(int i = 0; i < mat->rows; i++){
        for(int j = 0; j < mat->cols; j++){
            printf("Enter value for [%d,%d]: ", i, j);
            scanf("%lf", (*(mat->data+i)+j));
        }
    }
}

int main() {
    printf("Hello, World!\n");
    Matrix mat = newCazMatrix(3, 3);
    Matrix id = newIdentityMatrix(3);
    FillMatrix(mat);
    PrintMatrix(id);
    PrintMatrix(mat);
    PrintMatrix(subtractMatrix(mat, id));
    freeCazMatrix(&mat);
    return 0;
}