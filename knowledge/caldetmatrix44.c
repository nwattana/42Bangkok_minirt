#include <stdio.h>

// Function to calculate the determinant of a 3x3 submatrix
int calculate3x3Determinant(int matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Function to calculate the determinant of a 4x4 matrix
int calculate4x4Determinant(int matrix[4][4]) {
    int det = 0;
    int submatrix[3][3];

    int i = 0;
    while (i < 4) {
        int row = 1;
        while (row < 4) {
            int subCol = 0;
            int col = 0;
            while (col < 4) {
                if (col != i) {
                    submatrix[row - 1][subCol] = matrix[row][col];
                    subCol++;
                }
                col++;
            }
            row++;
        }

        int sign = (i % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][i] * calculate3x3Determinant(submatrix);
        i++;
    }

    return det;
}

int main() {
    int matrix[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    int determinant = calculate4x4Determinant(matrix);

    printf("Determinant of the 4x4 matrix:\n");
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("= %d\n", determinant);

    return 0;
}
