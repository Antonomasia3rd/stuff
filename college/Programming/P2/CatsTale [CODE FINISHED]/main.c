#include <stdio.h>
#include <string.h>
int main() {
    int num;
    int purr = 0, meoww = 0, purrmeoww = 0;
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        if (num % 3 == 0 && num % 5 == 0) purrmeoww++;
        else if (num % 3 == 0) purr++;
        else if (num % 5 == 0) meoww++;
    }
    printf("%d %d %d\n", purr, meoww, purrmeoww);
    return 0;}
