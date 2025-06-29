#include <stdio.h>

int main(void) {
    
    int age;
    char initial;

    scanf("%d", &age); // 50 엔터(\n처리)
    scanf(" %c", &initial);

    printf("나이: %d, 이니셜: %c", age, initial);


    return 0;
}