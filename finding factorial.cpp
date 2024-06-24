#include <stdio.h>
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    
    return fact;
}

int main() {
    int number;
    
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        
        unsigned long long fact = factorial(number);
        printf("Factorial of %d is: %llu\n", number, fact);
    }
    
    return 0;
}

