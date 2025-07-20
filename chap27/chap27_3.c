#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int rows = 3, cols = 4, i, j;

    // 1. 행을 위한 포인터 배열 할당 (int* 3개)
    int** arr = (int**) malloc(rows * sizeof(int*));

    // 2. 각 행에 대해 열 공간 할당
    for (i = 0; i < rows; i++) {
        arr[i] = (int*) malloc(cols * sizeof(int));
    }

    // 3. 일반 2차원배열처럼 사용
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arr[i][j] = i * 10 * j;
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }

    // 4. 해제는 할당의 역순 (각 열을 먼저 해제)
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}