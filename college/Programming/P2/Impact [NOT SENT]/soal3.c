#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Membaca jumlah pukulan

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);  // Membaca jumlah daun elektro pada awalnya

    int kubus[3] = {x, y, z};  // Menyimpan jumlah daun elektro pada masing-masing kubus

    // Loop untuk membaca nomor kubus yang dipukul sebanyak n kali
    for (int i = 0; i < n; i++) {
        int kubus_pukul;
        scanf("%d", &kubus_pukul);

        // Mengubah indeks kubus_pukul menjadi indeks array (indeks dimulai dari 0)
        kubus_pukul--;

        // Memanipulasi jumlah daun elektro pada kubus yang dipukul dan tetangganya
        if (kubus_pukul == 0) {
            kubus[0] = kubus[0] ^ kubus[1];  // XOR untuk kubus 1
            kubus[1] = kubus[1] ^ kubus[2];  // XOR untuk kubus 2
        } else if (kubus_pukul == 1) {
            kubus[1] = kubus[1] ^ kubus[0];  // XOR untuk kubus 2
            kubus[0] = kubus[0] ^ kubus[2];  // XOR untuk kubus 1
            kubus[2] = kubus[2] ^ kubus[1];  // XOR untuk kubus 3
        } else if (kubus_pukul == 2) {
            kubus[2] = kubus[2] ^ kubus[1];  // XOR untuk kubus 3
            kubus[1] = kubus[1] ^ kubus[0];  // XOR untuk kubus 2
        }
    }

    // Menampilkan hasil jumlah daun elektro pada setiap kubus
    printf("%d %d %d\n", kubus[0], kubus[1], kubus[2]);

    return 0;
}
