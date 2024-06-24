#include <stdio.h>
#include <stdlib.h>


void concatenateArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    
    int resultSize = size1 + size2;
    int *result = (int *)malloc(resultSize * sizeof(int));
    
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    
    concatenateArrays(arr1, size1, arr2, size2, result);

    
    printf("Concatenated Array: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    
    free(result);

    return 0;
}

