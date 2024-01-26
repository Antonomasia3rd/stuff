#include <stdio.h>
// pemikiran logic yang tidak bagus, perbaiki di rumah nanti
void kucinghitam(int A[3][3], int B[3][2], int result[3][2])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int A[3][3];
    int B[3][2];
    int result[3][2];
    for (int i = 0; i < 3; i++)
        {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
        {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Hitung
    kucinghitam(A, B, result);

    // Print ke console
    for (int i = 0; i < 3; i++)
        {
        for (int j = 0; j < 2; j++)
        {
            printf("%d", result[i][j]);
            if (j < 1)

            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
