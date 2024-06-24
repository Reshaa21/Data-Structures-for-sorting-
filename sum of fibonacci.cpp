#include <stdio.h>
long long fibonacciSum(int n) {
    if (n <= 0)
        return 0;
    long long sum = 0;
    long long a = 0;
    long long b = 1; 
    
    for (int i = 1; i <= n; ++i) {
        sum += a; 
        long long next = a + b; 
        a = b; 
        b = next; 
    }
    
    return sum;
}

int main() {
    int n;
    
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);
    long long sum = fibonacciSum(n);
    
    printf("Sum of Fibonacci series up to %d terms is: %lld\n", n, sum);
    
    return 0;
}

