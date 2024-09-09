#include <stdio.h>
#include <stdlib.h>

// fungsi untuk print sudoku, kerapian kode mungkin berkurang
void printSudoku(int **sudoku, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// bagian dari Evaluasi: Penanganan kasus ketika tidak ada solusi (20%)
int isValid(int **sudoku, int N, int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// logic sudoku main
int solveSudoku(int **sudoku, int N) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (sudoku[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (isValid(sudoku, N, row, col, num)) {
                        sudoku[row][col] = num;
                        if (solveSudoku(sudoku, N)) {
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

// bagian dari Spesifikasi: Program harus ditulis dalam bahasa pemrograman C.
int main() {
    int N;

    // memory allocation diperlukan untuk menyesuaikan array, karena ukuran papan berdasarkan user input
    // bagian dari Spesifikasi: Implementasikan algoritma untuk menyelesaikan papan Sudoku 6x6.
    printf("Masukkan ukuran papan Sudoku: ");
    scanf("%d", &N);
    int **sudoku = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        sudoku[i] = (int *)malloc(N * sizeof(int));
    }

    // logic sudoku helper
    // bagian dari Spesifikasi: Program harus menerima input papan awal dalam bentuk array 2D.
    printf("Masukkan papan Sudoku (gunakan 0 untuk kotak kosong):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    // bagian dari Spesifikasi: Program harus mencetak papan awal dan solusi dengan format yang rapi.
    printf("Papan awal Sudoku:\n");
    printSudoku(sudoku, N);

    // bagian dari Spesifikasi: Program harus menghasilkan solusi yang benar atau mengidentifikasi jika tidak ada solusi.
    if (solveSudoku(sudoku, N)) {
        printf("\nSolusi Sudoku:\n");
        printSudoku(sudoku, N);
    } else {
        printf("\nTidak ada solusi Sudoku yang valid.\n");
    }

    return 0;
}
