#include <stdio.h>

int main(void) {
    int age = 20;
    int height = 180;

    // && : 양쪽항이 모두 참이면 전체가 참
    printf("결과: %d\n", (age >= 19 && height >= 170));

    // || : 양쪽항 중에 하나만 참이면 전체가 참
    printf("결과: %d\n", (age >= 29 || height >= 190));

    printf("20세가 아닌가? 결과: %d\n", !(age == 20));

    return 0;
}