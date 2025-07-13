
#include <stdio.h>

int main(void) {
 
    char str[] = "ACE";

    printf("*(str + 1)의 결과: %c\n", *(str + 1));
    printf("*str + 1의 결과: %c\n", *str + 1);

    return 0;
}