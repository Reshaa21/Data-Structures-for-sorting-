#include <stdio.h>

int main() {
    int arr[] = {23, 1, 56, 3, 78, 9, 12, 45, 67, 89, 34, 21, 44, 55, 66, 77, 88, 99, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Every 5th iterated element: ");
    for (int i = 4; i < size; i += 5) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

