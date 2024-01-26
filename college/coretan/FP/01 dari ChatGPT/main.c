#include <stdio.h>

#define N 6

int sudoku[N][N]; // Variabel global untuk papan Sudoku

void printSudoku(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int isValid(int size, int row, int col, int num) {
    for (int i = 0; i < size; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

int solveSudoku(int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (sudoku[row][col] == 0) {
                for (int num = 1; num <= size; num++) {
                    if (isValid(size, row, col, num)) {
                        sudoku[row][col] = num;
                        if (solveSudoku(size)) {
                            return 1;
                        }
                        sudoku[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int size;
    printf("Masukkan ukuran papan Sudoku (misalnya, 6): ");
    scanf("%d", &size);

    printf("Masukkan papan Sudoku (gunakan 0 untuk kotak kosong):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    printf("Papan awal Sudoku:\n");
    printSudoku(size);

    if (solveSudoku(size)) {
        printf("\nSolusi Sudoku:\n");
        printSudoku(size);
    } else {
        printf("\nTidak ada solusi Sudoku yang valid.\n");
    }

    return 0;
}
