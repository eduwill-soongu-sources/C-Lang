#include <stdio.h>

int main(void) {
 
    char a[5] = "hello";
    char b[5];

    printf("문자열 입력: ");
    scanf("%s", b);

    printf("a: %s\n", a);
    printf("b: %s\n", b);

    return 0;
}