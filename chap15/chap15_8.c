#include <stdio.h>

int main(void) {
 
    int i = 0, j, result = 0;
    while (i < 5)
    {
        i++;
        printf("i: %d\n", i);
        if (i == 3) {
            continue;
        }
        for (j = 0; j < i; j++) {
            printf("j: %d\n", j);
            result++;
        }
        printf("result: %d\n", result);
        if (result > 8) {
            break;
        }
    }
    printf("%d", result);
    

    return 0;
}