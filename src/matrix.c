// #include "matrix.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int dim;
    double *vec;
} Vector;

typedef struct Matrix {
    int rows;
    int cols;
    double **mat;
} Matrix;

// typedef struct Tensor {
//     int n;
//     void *ptr;
// }

// typedef struct matSpace{
//     int cnt;
//     Matrix *space;
// } MatrixSpace;

Vector vecCreate(int dims);
Vector vecSum (Vector a, Vector b);
double scalMul (Vector a, Vector b);

Matrix matCreate(int rows, int cols);
Matrix matSum(Matrix a, Matrix b);
Matrix matSub(Matrix a, Matrix b);
Matrix matMul(Matrix a, Matrix b);
int printMatrix(Matrix a);
int matRemove(Matrix a);

int main() {
    Matrix a = matCreate(3, 3);

    for (int i = 0, cnt = 1; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++, cnt++) {
            a.mat[i][j] = cnt;
        }
    }


    printMatrix(a);
    printf("\n");
    printMatrix(matSum(a, a));
    printf("\n");
    printMatrix(matSub(a, a));
    printf("\n");
    matRemove(a);

    return 0;
}

Vector vecCreate(int dims){
    Vector a;
    a.dim = dims;
    (a.vec) = (double *)malloc(dims * sizeof(double));
    return a;
}

Vector vecSum (Vector a, Vector b){
    Vector c = {a.dim, NULL};
    if (a.dim == b.dim)
    for (int i = 0; i < a.dim; i++) (c.vec)[i] =  (a.vec)[i] + (b.vec)[i];
    return c;
}

double scalMul (Vector a, Vector b){
    double s = 0;
    for (int i = 0; i < a.dim; i++) s +=  (a.vec)[i] * (b.vec)[i];
    return s;
}

Matrix matCreate(int rows, int cols) {
    Matrix a;
    a.cols = cols;
    a.rows = rows;
    (a.mat) = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) (a.mat[i]) = (double *)malloc(cols * sizeof(double *));
    return a;
}

Matrix matSum(Matrix a, Matrix b) {
    Matrix c;
    c.cols = b.cols;
    c.rows = b.rows;
    (c.mat) = (double **)malloc(c.rows * sizeof(double *));
    for (int i = 0; i < c.rows; i++) (c.mat[i]) = (double *)malloc(c.cols * sizeof(double *));
    for (int i = 0; i < c.rows; i++)
        for (int j = 0; j < c.cols; j++) c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
    return c;
}

Matrix matSub(Matrix a, Matrix b) {
    Matrix c;
    c.cols = b.cols;
    c.rows = b.rows;
    (c.mat) = (double **)malloc(c.rows * sizeof(double *));
    for (int i = 0; i < c.rows; i++) (c.mat[i]) = (double *)malloc(c.cols * sizeof(double *));
    for (int i = 0; i < c.rows; i++)
        for (int j = 0; j < c.cols; j++) c.mat[i][j] = a.mat[i][j] - b.mat[i][j];
    return c;
}

Matrix matMul(Matrix a, Matrix b) {
    Matrix c = {a.rows, b.cols, NULL};
    if (a.cols == b.rows) {
        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                    Vector u = vecCreate(a.rows);
                    u.vec = (a.mat)[i];
                    Vector v = vecCreate(b.cols);
                    v.vec = (b.mat)[j];                 // Нужно сделать обращение к столбцам 
                    (c.mat)[i][j] = scalMul(u, v);
            }
        }
    }
    return c;
}

int printMatrix(Matrix a) {
    int res = true;
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            printf("%.lf ", a.mat[i][j]);
        }
        printf("\n");
    }
    return res;
}

int matRemove(Matrix a) {
    int res = true;
    for (int i = 0; i < a.rows; i++) free(a.mat[i]);
    free(a.mat);
    return res;
}