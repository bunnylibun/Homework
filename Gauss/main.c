#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-9

void swap_rows(double** matrix, int i, int j, int m) {
    for (int k = 0; k < m; k++) {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

void multiply_row(double** matrix, int i, int m, double num) {
    for (int k=0; k<m; k++) {
        matrix[i][k] *= num;
    }
}

void subtract_rows(double** matrix, int i, int j, int m, double num) {
    for (int k=0; k<m; k++) {
        matrix[i][k] -= matrix[j][k]*num;
    }
}

int main(void) {
    int n=0, m=0;
    double det=1.0;
    int sign = 1;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printf("Enter number of columns: ");
    scanf("%d", &m);
    if (n != m) {
        printf("Error: determinant exists only for square matrices!");
        return 1;
    }
    double **matrix = (double**)malloc(n*sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(m*sizeof(double));
    }
    printf("Enter matrix data:\n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%lf", matrix[i]+j);
        }
    }
    for (int i=0; i<n; i++) {
        int pivot = i;
        while (pivot < n && fabs(matrix[pivot][i]) < EPS) {
            pivot++;
        }
        if (pivot == n) {
            det = 0.0;
        }
        else {
            if (pivot != i) {
                swap_rows(matrix, i, pivot, m);
                sign = -sign;
            }
            for (int j=i+1; j<n; j++) {
                if (fabs(matrix[i][i]) > EPS) {
                    double num = matrix[j][i]/matrix[i][i];
                    subtract_rows(matrix, j, i, m, num);
                }
            }
        }
    }
    if (det != 0.0) {
        for (int i=0; i<n; i++) {
            det *= matrix[i][i];
        }
        det *= sign;
    }
    printf("Determinant = %.6f\n", det);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
