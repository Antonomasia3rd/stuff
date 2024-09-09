#include <stdio.h>

int main() {
    float A[10][10], B[10][10], C[10][10];
    int N, M, K, i, j, k;
    float v;

    printf("\nJumlah Baris Matriks A (Maks 10): M = ");
    scanf("%d", &M);

    printf("\nJumlah Kolom Matriks A dan Baris Matriks B (Maks 10): K = ");
    scanf("%d", &K);

    printf("\nJumlah Kolom Matriks B (Maks 10): N = ");
    scanf("%d", &N);

    // Input Matriks A
    for (i = 0; i < M; i++) {
        for (j = 0; j < K; j++) {
            printf("\nInput A(%d, %d) = ", i, j);
            scanf("%f", &v);
            A[i][j] = v;
        }
    }

    // Input Matriks B
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            printf("\nInput B(%d, %d) = ", i, j);
            scanf("%f", &v);
            B[i][j] = v;
        }
    }

    // Perkalian dua matriks
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = 0;
            for (k = 0; k < K; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    // Mencetak hasil perkalian matriks
    for (i = 0; i < M; i++) {
        printf("[");
        for (j = 0; j < N; j++) {
            printf(" %f", C[i][j]);
        }
        printf("]\n");
    }

    return 0;
}
