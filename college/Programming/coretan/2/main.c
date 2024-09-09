#include <stdio.h>
int pascal(int n, int k) { // hitung koefisien binomial C(n, k)
    if (k == 0 || k == n) return 1;
    return pascal(n - 1, k - 1) + pascal(n - 1, k);
}
void percetakangaming(int baris) { // print segitiga Pascal
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < baris - i - 1; j++) // print leading spaces
            printf(" ");
        for (int j = 0; j <= i; j++) // print koefisien binomial
            printf("%d ", pascal(i, j));
        printf("\n");
    }
}
int main() {
    int baris;
    printf("Masukkan jumlah baris untuk segitiga Pascal: ");
    scanf("%d", &baris);
    percetakangaming(baris);
    return 0;
    // kesimpulannya: aku gak bisa ngeluruskan yang kanan p p p
}
