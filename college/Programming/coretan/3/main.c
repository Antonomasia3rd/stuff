#include <stdio.h>

int main() {
    int (*ptr)[3][4]; // Declare a pointer to a 3x4 integer array

    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    ptr = &arr; // Set the pointer to point to the array

    // Access and print the elements using the pointer
    printf("Elements of the 3x4 array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", (*ptr)[i][j]);
        }
        printf("\n");
    }

    return 0;
}
