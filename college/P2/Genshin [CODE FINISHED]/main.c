#include <stdio.h>

int main() {
    int ar,worldLevel;
    scanf("%d", &ar);
    if (ar >= 1 && ar <= 19) {
        worldLevel = 0;
    } else if (ar >= 20 && ar <= 25) {
        worldLevel = 1; // jangan lupa ascension
    } else if (ar >= 26 && ar <= 29) {
        worldLevel = 2;
    } else if (ar >= 30 && ar <= 35) {
        worldLevel = 3; // jangan lupa ascension
    } else if (ar >= 36 && ar <= 39) {
        worldLevel = 4;
    } else if (ar >= 40 && ar <= 45) {
        worldLevel = 5; // jangan lupa ascension
    } else if (ar >= 46 && ar <= 50) {
        worldLevel = 6; // jangan lupa ascension
    } else if (ar >= 51 && ar <= 54) {
        worldLevel = 7;
    } else if (ar >= 55 && ar <= 60) {
        worldLevel = 8;
    } else {
        printf("\"How about we explore the area ahead of us later :p\" ~ Paimon\n[AR tidak boleh kurang dari 1, atau lebih dari 60]\n");
        return 1;  // lol lmao yang buat soal pasti sepuh genshin
    }
    printf("%d\n",worldLevel);
    return 0;
}
