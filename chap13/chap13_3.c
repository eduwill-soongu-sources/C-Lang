#include <stdio.h>

int main(void) {
    
    int money = 15000;

    // money가 10000원 이상이면 플렉스, 아니면 학식
    printf("오늘 점심은? %s\n", (money >= 10000) ? "플렉스!" : "학식");


    return 0;
}