#include <stdio.h> // common sense
#include <string.h> // buat strlen sama strchr
int main() {
    char masukan[100];
    int hitungVokal = 0;
    printf("Masukkan kata: ");
    fgets(masukan, sizeof(masukan), stdin);
    printf("\nString setelah perubahan: ");
    for (int i = 0; i < strlen(masukan); i++) {
        char c = masukan[i];
        if (c == 'A' || c == 'a') printf("4");
        else if (c == 'I' || c == 'i') printf("1");
        else printf("%c", c);
        if (strchr("AEIOUaeiou", c)) hitungVokal++;
    }
    printf("Jumlah vokal dalam string: %d", hitungVokal);
    return 0;
}
