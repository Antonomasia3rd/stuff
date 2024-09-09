#include <stdio.h>

int binarySearch(char *nama[], int size, char *cari) {
    int kanan = 0;
    int kiri = size - 1;
    while (kanan <= kiri) {
        int tengah = kanan + (kiri - kanan) / 2; // hitung indeks tengahnya
        if (nama[tengah] == cari) return tengah; // targetnya ketemu
        else if (nama[tengah] < cari) kanan = tengah + 1; // targetnya di setengah kanan
        else kiri = tengah - 1; // targetnya di setengah kiri
    }
    return -1; // targetnya gak ketemu
}

int main() {
    char *nama[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank"};
    int size = sizeof(nama) / sizeof(nama[0]);
    char *cari = "Eve";
    int hasil = binarySearch(nama, size, cari);
    if (hasil != -1) printf("%s ada di index %d", cari, hasil);
    else printf("%s tidak ditemukan", cari);
    return 0;
}
