#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int columns;
    int rows;
    double **mat;
} Matrix;

Matrix matCreate(int rows, int columns);
Matrix matSum(Matrix a, Matrix b);
Matrix matSub(Matrix a, Matrix b);
int printMatrix(Matrix mat);