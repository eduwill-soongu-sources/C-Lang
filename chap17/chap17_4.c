#include <stdio.h>

int main(void) {
 
    int map[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };

    int rows = sizeof(map) / sizeof(map[0]);
    int cols = sizeof(map[0]) / sizeof(int);

    // printf("size: %d\n", sizeof(map[0]));
    printf("이 배열은 %d행 %d열입니다.\n", rows, cols);

    return 0;
}