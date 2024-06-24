#include <stdio.h>

int main(){
    int array[10];
    int n = 10;
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        array[i] = 10 - i;
        printf("%d ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
