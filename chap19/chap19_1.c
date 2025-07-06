#include <stdio.h>
#include <string.h>  // 문자열 전용 함수를 사용 가능!

int main(void) {
    
    char a[] = "apple";
    char b[] = "Hong Gildong";
    char c[20] = "hello";

    printf("단어 '%s'의 글자 수는 %d입니다.\n", a, strlen(a));
    printf("문장 '%s'의 글자 수는 %d입니다.\n", b, strlen(b));
    printf("단어 '%s'의 글자 수는 %d입니다.\n", c, strlen(c));
    
    return 0;
}