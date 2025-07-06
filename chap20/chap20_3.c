#include <stdio.h>

void failedLevelUp(int myLevel) {

    printf("> 특수 훈련소 입장! 현재 레벨 : %d\n", myLevel);
    myLevel = 99;
    printf("> 특수 훈련소 퇴장! 현재 레벨 : %d\n", myLevel);
}

int main(void) {
    
    int myLevel = 10;
    printf("훈련소 가기 전 내 레벨: %d\n", myLevel);

    failedLevelUp(myLevel);

    printf("훈련소 다녀온 후 내 레벨: %d\n", myLevel);

    return 0;
}

