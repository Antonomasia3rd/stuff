#include <stdio.h>
#include <string.h>

// Deklarasi struct terlebih dahulu
// (dibuat lebih simpel agar anggotanya bisa dimasukkan dengan mudah)
struct Mahasiswa {
    char nama[50];
    int nim;
    double ipk;
};

int main() {

    // Deklarasi variabel, lalu
    // tambahkan anggota pada variabelnya
    struct Mahasiswa anggota[] = {
        {"Antonomasia", 16512, 0.0},
        {"Amiya", 4255, 0.0},
        // tambahkan seperlunya
    };

    // buat nampilkan berapa mahasiswa yang ada di struct
    int totalMhs = sizeof(anggota) / sizeof(anggota[0]);
    printf("\nAda %d mahasiswa pada struct\n(edit kode untuk menambahkan anggota)\n\n", totalMhs);

    // Perintah untuk masukkan IPK
    for (int i = 0; i < totalMhs; i++) {
        printf("Masukkan IPK untuk %s (NIM: %d): ", anggota[i].nama, anggota[i].nim);
        scanf("%lf", &anggota[i].ipk);
    }

    // Tampilkan rincian dari data struct + input
    printf("\nRincian:\n");
    for (int i = 0; i < totalMhs; i++) {
        printf("\nMahasiswa %d:\n", i + 1);
        printf("Nama: %s\n", anggota[i].nama);
        printf("NIM: %d\n", anggota[i].nim);
        printf("IPK: %.2lf\n", anggota[i].ipk);
    }

    // Hitung rata-rata IPK
    double totalIPK = 0.0;
    for (int i = 0; i < totalMhs; i++) {
        totalIPK += anggota[i].ipk;
    }
    double rataIPK = totalIPK / totalMhs;
    printf("\nRata-rata IPK dari %d mahasiswa: %.2lf\n", totalMhs, rataIPK);

    // Selesai
    return 0;
}
