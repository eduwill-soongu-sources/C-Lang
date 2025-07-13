#include <stdio.h>


void countdown(int n) {

    // 1. 종료 조건
    if (n <= 0) {
        printf("발사!\n");
        return;
    }

    printf("%d...\n", n);
    // 2. 재귀 호출
    countdown(n - 1);
}

int main(void) {
 
    countdown(3);

    return 0;
}