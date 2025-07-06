#include <stdio.h>

int main(void) {
 
    char str1[] = "Hello";
    printf("str1 size: %d\n", sizeof(str1));
    
    char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("str2 size: %d\n", sizeof(str2));

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
    return 0;
}