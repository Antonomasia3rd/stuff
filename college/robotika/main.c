#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// deklarasi fungsi
void selesaikanMaze(char maze[][100], int baris, int kolom, int barisAwal, int kolomAwal, char pergerakan[]);
bool aman(char maze[][100], int baris, int kolom, int barisBaru, int kolomBaru);
bool gerakanValid(int baris, int kolom, int barisBaru, int kolomBaru);

// main logic
int main() {
    int baris, kolom;

    // user input pada baris dan kolom
    printf("Masukkan jumlah baris dan kolom\n(pisahkan dengan spasi)\n");
    scanf("%d %d", &baris, &kolom);

    char maze[100][100];

    // user input pada layout maze
    printf("\nMasukkan tata letak maze:\n");
    for (int i = 0; i < baris; ++i) {
        scanf("%s", maze[i]);
    }

    // temukan posisi awal robot ('*')
    int barisAwal = -1, kolomAwal = -1;
    for (int i = 0; i < baris; ++i) {
        for (int j = 0; j < kolom; ++j) {
            if (maze[i][j] == '*') {
                barisAwal = i;
                kolomAwal = j;
                break;
            }
        }
        if (barisAwal != -1) {
            break;
        }
    }

    // user input pada pergerakan
    char pergerakan[100];
    printf("\nAtur pergerakan robot\n(w untuk atas, a untuk kiri, s untuk bawah, d untuk kanan)\n");
    scanf("%s", pergerakan);

    // selesaikan maze berdasarkan user input
    selesaikanMaze(maze, baris, kolom, barisAwal, kolomAwal, pergerakan);

    return 0;
}

// main logic maze
void selesaikanMaze(char maze[][100], int baris, int kolom, int barisAwal, int kolomAwal, char pergerakan[]) {
    int barisRobot = barisAwal, kolomRobot = kolomAwal;

    // tandai posisi awal robot (workaround)
    maze[barisRobot][kolomRobot] = '#';

    // iterasi etc.
    for (int i = 0; i < strlen(pergerakan); ++i) {
        char gerakan = pergerakan[i];

        // main logic posisi
        int barisBaru = barisRobot, kolomBaru = kolomRobot;
        if (gerakan == 'w') {
            barisBaru--;
        } else if (gerakan == 'a') {
            kolomBaru--;
        } else if (gerakan == 's') {
            barisBaru++;
        } else if (gerakan == 'd') {
            kolomBaru++;
        }

        // periksa pergerakan
        if (aman(maze, baris, kolom, barisBaru, kolomBaru)) {
            barisRobot = barisBaru;
            kolomRobot = kolomBaru;
            // tandai jalur dengan '#'
            maze[barisRobot][kolomRobot] = '#';
        } else {
            // print notifikasi robot tertabrak
            printf("\nRobot Menabrak Obstacle.\nTidak bisa melakukan\ngerakan ke %c dari (%d, %d).\n", gerakan, barisRobot, kolomRobot);
        }
    }

    // penambahan agar rapi
    printf("\nHasil:\n");

    // print hasil maze
    for (int i = 0; i < baris; ++i) {
        printf("%s\n", maze[i]);
    }
}

// cegah obstacle
bool aman(char maze[][100], int baris, int kolom, int barisBaru, int kolomBaru) {
    return gerakanValid(baris, kolom, barisBaru, kolomBaru) && maze[barisBaru][kolomBaru] != 'o' && maze[barisBaru][kolomBaru] != '#';
}

// cegah tembok
bool gerakanValid(int baris, int kolom, int barisBaru, int kolomBaru) {
    return barisBaru >= 0 && barisBaru < baris && kolomBaru >= 0 && kolomBaru < kolom;
}
