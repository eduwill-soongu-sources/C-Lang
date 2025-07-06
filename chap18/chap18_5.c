#include <stdio.h>

int main(void) {
    
    char src[] = "pass";
    char dest[10];

    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    // 널문자를 추가해줘야 함
    dest[i] = '\0';

    printf("%s", dest);
    
    return 0;
}