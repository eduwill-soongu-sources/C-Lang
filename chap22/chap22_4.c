#include <stdio.h>

int main(void) {
 
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    int i;
    for (i = 0; i < 5; i++) {
        printf("[%d]위치의 값: %d\n", i, *(ptr + i));
    }

    return 0;
}