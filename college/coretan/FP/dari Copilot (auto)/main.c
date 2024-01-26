// Program Sudoku dalam bahasa C
// Mengimplementasikan algoritma backtracking untuk menyelesaikan papan Sudoku 6x6

#include <stdio.h>
#include <stdbool.h>

// Ukuran papan Sudoku
#define N 6

// Fungsi untuk mencetak papan Sudoku dengan format yang rapi
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Fungsi untuk mengecek apakah angka yang diberikan valid untuk dimasukkan di sel tertentu
bool isValid(int board[N][N], int row, int col, int num) {
  // Cek baris
  for (int j = 0; j < N; j++) {
    if (board[row][j] == num) {
      return false;
    }
  }
  // Cek kolom
  for (int i = 0; i < N; i++) {
    if (board[i][col] == num) {
      return false;
    }
  }
  // Cek subgrid 2x3
  int startRow = row - row % 2;
  int startCol = col - col % 3;
  for (int i = startRow; i < startRow + 2; i++) {
    for (int j = startCol; j < startCol + 3; j++) {
      if (board[i][j] == num) {
        return false;
      }
    }
  }
  // Jika semua kondisi terpenuhi, angka valid
  return true;
}

// Fungsi untuk menyelesaikan papan Sudoku dengan algoritma backtracking
// Mengembalikan true jika ada solusi, false jika tidak ada
bool solveSudoku(int board[N][N], int row, int col) {
  // Jika sudah mencapai akhir papan, berarti sudah selesai
  if (row == N - 1 && col == N) {
    return true;
  }
  // Jika sudah mencapai akhir kolom, lanjut ke baris berikutnya
  if (col == N) {
    row++;
    col = 0;
  }
  // Jika sel sudah terisi, lanjut ke sel berikutnya
  if (board[row][col] > 0) {
    return solveSudoku(board, row, col + 1);
  }
  // Coba semua kemungkinan angka dari 1 sampai 6
  for (int num = 1; num <= N; num++) {
    // Jika angka valid, masukkan ke sel
    if (isValid(board, row, col, num)) {
      board[row][col] = num;
      // Lanjut ke sel berikutnya dengan rekursif
      if (solveSudoku(board, row, col + 1)) {
        return true;
      }
    }
    // Jika tidak ada solusi, kembalikan sel ke 0 dan coba angka lain
    board[row][col] = 0;
  }
  // Jika tidak ada angka yang valid, berarti tidak ada solusi
  return false;
}

// Fungsi utama untuk menjalankan program
int main() {
  // Contoh input papan awal dalam bentuk array 2D
  // 0 berarti sel kosong
  int board[N][N] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  // Cetak papan awal
  printf("Papan awal:\n");
  printBoard(board);

  // Coba menyelesaikan papan Sudoku
  if (solveSudoku(board, 0, 0)) {
    // Jika ada solusi, cetak solusi
    printf("Solusi:\n");
    printBoard(board);
  } else {
    // Jika tidak ada solusi, cetak pesan
    printf("Tidak ada solusi.\n");
  }

  return 0;
}
