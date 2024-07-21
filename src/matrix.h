#include "data_structs.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct Matrix {
    int rows;
    int cols;
    double **mat;
} Matrix;

// typedef struct Tensor {
//     int n;
//     void *ptr;
// }

typedef struct matSpace{
    int cnt;
    Matrix *space;
} MatrixSpace;

Matrix matSum(Matrix a, Matrix b);
Matrix matSub(Matrix a, Matrix b);
Matrix matMul(Matrix a, Matrix b);
Matrix matByNum(Matrix a, double k);

Matrix matTran(Matrix a);
Matrix matMinor(Matrix a, int i, int j);
Matrix matCompl(Matrix a);
double matDet(Matrix a);
Matrix matInv(Matrix a);
double matTrace(Matrix a);

int printMatrix(Matrix a);
Matrix matCreate(int rows, int cols);
int matRemove(Matrix a);