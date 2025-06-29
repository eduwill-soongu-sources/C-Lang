#include <stdio.h>

int main(void) {
 
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            continue;
        }
        if (i == 8) {
            break;
        }

        printf("%d번 손님 입장!\n", i);
    }
    
    return 0;
}