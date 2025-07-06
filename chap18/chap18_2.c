#include <stdio.h>

int main(void) {
 
    char userName[20];

    printf("당신의 이름은 ?? ");

    // 문자열은 &를 붙이지 않음
    scanf("%s", userName);

    printf("당신은 %s님이시군요?? \n", userName);
    
    return 0;
}