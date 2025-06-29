#include <stdio.h>

int main(void) {

    int i = 5, j = 5;
    int result1, result2;

    result1 = ++i;
    printf("전위 증감: result1 = %d, i = %d\n", result1, i);

    result2 = j++;
    printf("후위 증감: result2 = %d, j = %d\n", result2, j);

    return 0;
}