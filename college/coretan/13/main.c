#include <stdio.h>

int main() {
    long long NRP; // harus long long, kalau int nanti kacau

    printf("Masukkan NRP: ");
    if (scanf("%lld", &NRP) != 1) { // harus %lld, kalau %d nanti kacau
        printf("NRP tidak valid.\n");
        return 1;
    }

    // periksa panjang NRP
    long long periksa = NRP; int totaldigit = 0; // long long, alasan yang sama
    while (periksa > 0) {periksa /= 10; totaldigit++;}
    if (totaldigit != 10) {
        printf("NRP tidak valid. Harap masukkan 10 digit.\n");
        return 1;
    }

    // workaround yang cerdas, sangat tidak recommended kalau buat aplikasi betulan
    int departemen = NRP / 1000000; // 4 digit pertama
    int angkatan = (NRP / 10000) % 100; // 2 digit kedua
    int nomorurut = NRP % 10000; // 4 digit ketiga

    printf("Departemen ");
    switch (departemen) {
        case 5022:
            printf("Teknik Elektro\n");
            break;
        // tambahkan case untuk departemen lain kalau perlu,
        // gak mungkin nulis satu satu,
        // gak mungkin juga ngambil database online dari myITS,
        // terlalu jauh ilmunya :v
        default:
            printf("Tidak Diketahui\n");
    }
    printf("Angkatan %d/%d\n", angkatan, angkatan + 1);
    printf("Nomor Urut %d\n", nomorurut);

    return 0;
}
