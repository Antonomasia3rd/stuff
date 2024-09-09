#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j;
    int operasi = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            operasi++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nBubble Sort\n");
    for (i = 0; i < n; i++) {
        printf("%d%s", arr[i], i == n - 1 ? "\n" : " ");
    }
    printf("Operasi: %d\n", operasi);
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    int operasi = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        operasi++;
        while (j >= 0 && arr[j] > key) {
            operasi++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("\nInsertion Sort\n");
    for (i = 0; i < n; i++) {
        printf("%d%s", arr[i], i == n - 1 ? "\n" : " ");
    }
    printf("Operasi: %d\n", operasi);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr_bubble[n], arr_insertion[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr_bubble[i]);
        arr_insertion[i] = arr_bubble[i];
    }
    bubbleSort(arr_bubble, n);
    insertionSort(arr_insertion, n);
    return 0;
}
