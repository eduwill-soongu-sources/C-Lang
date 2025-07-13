#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
 
    printf("%d번째 피보나치 수: %d\n", 7, fibonacci(7));
    
    return 0;
}