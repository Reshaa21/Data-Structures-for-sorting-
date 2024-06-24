#include <stdio.h>

int findMissingElement(int arr[], int size) {
    int n = size + 1; 
    int total_sum = (n * (n + 1)) / 2; 
    int array_sum = 0;

    for (int i = 0; i < size; i++) {
        array_sum += arr[i];
    }

    return total_sum - array_sum; 
}

int main() {
    int arr[] = {1, 2, 4, 6, 3, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missingElement = findMissingElement(arr, size);

    printf("The missing element is: %d\n", missingElement);

    return 0;
}

