#include <stdio.h>

// Function to find the largest element in a 2D matrix
int findLargestElement(int rows, int cols, int matrix[rows][cols]) {
    int largest = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }
        }
    }
    return largest;
}

int main() {
    // Define the dimensions of the matrix
    int rows = 3;
    int cols = 3;

    // Define and initialize the 2D matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Print the matrix
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Find and print the largest element in the matrix
    int largest = findLargestElement(rows, cols, matrix);
    printf("The largest element in the matrix is: %d\n", largest);

    return 0;
}

