#include <stdio.h>

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 2;
    int cols = 2;

    // Create a 2x2 matrix (you can initialize it as you prefer)
    int matrix[2][2] = {
        {1, 2},
        {3, 4}
    };

    // Call the printMatrix function to print the matrix
    printf("2D Matrix:\n");
    int *matrix_ptr[2];  // An array of pointers
    for (int i = 0; i < rows; i++) {
        matrix_ptr[i] = matrix[i];
    }
    printMatrix(matrix_ptr, rows, cols);

    return 0;
}
