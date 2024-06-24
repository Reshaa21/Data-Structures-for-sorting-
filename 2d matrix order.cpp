#include <iostream>
#include <vector>

int findLargestElement(std::vector<std::vector<int>>& matrix) {
    int largest = matrix[0][0];
    
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }
        }
    }
    
    return largest;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 6},
                                            {7, 8, 9}};
    
    int largestElement = findLargestElement(matrix);
    
    std::cout << "The largest element in the matrix is: " << largestElement << std::endl;
    
    return 0;
}
