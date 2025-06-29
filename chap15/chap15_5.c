#include <stdio.h>

int main(void) {
 
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d번 상자를 엽니다.\n", i);
        if (i == 7) {
            printf("보물 발견!! 탐색 종료!");
            break;
        }
    }
    
    return 0;
}