#include <stdio.h>

// 함수 선언
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);


int main(void) {

    int x, y;
    printf("두 개의 정수를 입력하세요!");
    scanf("%d %d", &x, &y);
    
    // 함수 호출!
    int result = add(x, y);
    printf("덧셈결과: %d\n", result);
    printf("뺄셈결과: %d\n", subtract(x, y));
    printf("곱셈결과: %d\n", multiply(x, y));
    printf("나눗셈결과: %.2f\n", divide(x, y));

    return 0;
}

// 함수 정의
int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
double divide(int a, int b) {
    return (double) a / b;
}