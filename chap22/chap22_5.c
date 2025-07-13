#include <stdio.h>

int main(void) {
    
    char str[] = "Hello";
    char *p = str;

    // int i = 0;
    
    printf("문자열 값: ");
    while (*p != '\0') {
        printf("%c", *p);
        p++;
    }


    return 0;
}