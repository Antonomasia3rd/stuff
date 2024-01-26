#include <stdio.h>
#include <string.h>

int main() {
    int num;
    // buat data jadi array
    // int arr[99];
    int count_purr = 0, count_meoww = 0, count_purrmeoww = 0;
    // int ib1=0;

    // loop untuk membaca bilangan bulat sampai -1 ditemukan
    while (1) {

        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
         // arr[ib1] = num;
         // ib1++;
    // }

    // buat loop yang panjang loopnya itu sepanjang isi array

    // Cek apakah bilangan habis dibagi 3 dan/atau 5
    printf("%d", ib1);
    for(int i=0; i<ib1; i++) {
        if (arr[i] % 3 == 0 && arr[i] % 5 == 0) {
                count_purrmeoww++;
            } else if (arr[i] % 3 == 0) {
                count_purr++;
            } else if (arr[i] % 5 == 0) {
                count_meoww++;
            }
    }

    // Menampilkan jumlah kata Purr, Meoww, dan PurrMeoww
    printf("%d %d %d\n", count_purr, count_meoww, count_purrmeoww);
    // thanks for your help hehe, it means a lot, my head aches from doing "if else"

    return 0;
}
