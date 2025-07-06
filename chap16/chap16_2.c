#include <stdio.h>

int main(void) {
    
    int ages[] = {24, 26, 23, 21, 18};

    int len = sizeof(ages) / sizeof(int);
    // printf("len: %d\n", len);

    for (int i = 0; i < len; i++) {
        printf("%d번째 나이는 %d살\n", (i + 1), ages[i]);
    }
    return 0;
}