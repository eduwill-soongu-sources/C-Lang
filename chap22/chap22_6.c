#include <stdio.h>

int main(void) {
 
    char str1[] = "Hello";

    str1[0] = 'J';

    printf("str1: %s\n", str1);
    
    char *str2 = "World";
    
    // str2[0] = 'Z'; // char 포인터로 문자열을 선언하면 못바꿈
    printf("str2: %s\n", str2);

    return 0;
}