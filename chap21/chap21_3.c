#include <stdio.h>

int main(void) {
 
    int characterHP = 50; // 캐릭터 현재 HP
    int *healPtr = &characterHP; // hp를 가리키는 포인터변수

    printf("치유 마법 시전 전 HP: %d\n", characterHP);
    
    printf("힐! 힐! 힐좀요!!\n");
    
    *healPtr += 30;

    printf("치유 마법 시전 후 HP: %d\n", characterHP);

    return 0;
}