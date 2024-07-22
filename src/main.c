#include "matrix.h"

int main() {
    double arr1[] = {
        0, 2, 3,
        4, 2, 6,
        7, 8, 9
    };

    Matrix a = arrayToMatrix(arr1, 3, 3);

    double arr2[] = {
        -1, 2, 3,
        4, 3, 6,
        7, 8, 5
    };

    Matrix a = arrayToMatrix(arr1, 3, 3);

    Matrix (*op[3])(Matrix a, Matrix b) = {matMul, matSub, matSum};

    printMatrix(a);
    printf("\n");

    for (int i = 0; i < 3; i++) {
        Matrix b = (op[i](a, a));
        printMatrix(b);
        printf("\n");
        matRemove(b);
    }
    printMatrix(matByNum(a, 2.4));
    printf("\n");
    printf("%d\n", matEqual(a, a));
    printf("\n");
    printf("%d\n", matEqual(a, matSub(a, a)));
    printf("\n");
    printMatrix(matTran(a));
    printf("\n");
    printMatrix(a);
    printf("\n");
    printf("%lf\n", matDet(a));
    printf("\n");
    printMatrix(matCompl(a));
    printf("\n");
    printMatrix(matMul(a, matInv(a)));
    printf("\n");
    printf("%lf\n", matTrace(a));
    printf("\n");
    matRemove(a);

    return 0;
}