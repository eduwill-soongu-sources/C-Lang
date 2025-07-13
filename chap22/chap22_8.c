#include <stdio.h>

int main(void) {
 
    // 포인터 배열로 구현한 문자열 배열
    char *fruits[3] = {"apple", "banana", "orange"};

    int i;
    for (i = 0; i < 3; i++) {
        printf("과일 : %s\n", fruits[i]);
    }



    return 0;
}