#include <stdio.h>
#include <math.h> // hanya untuk sqrt

int main() {
    printf("\nMasukkan:\n");
    double x1, y1, x2, y2, distance;
    printf("x1: ");
    scanf("%lf", &x1);
    printf("x2: ");
    scanf("%lf", &x2);
    printf("y1: ");
    scanf("%lf", &y1);
    printf("y2: ");
    scanf("%lf", &y2);
    distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    printf("\nJarak Euclidean nya adalah %.2lf\n", distance);
    return 0;
}
