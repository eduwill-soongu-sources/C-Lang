#include <stdio.h>

int main(void) {
    
    // 3x3 빙고판
    int bingo[3][3];
    int i, j;

    int rows = sizeof(bingo) / sizeof(bingo[0]);
    int cols = sizeof(bingo[0]) / sizeof(int);

    printf("----- 3x3 빙고판을 숫자로 채워주세요 -----\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("좌표 [%d][%d]에 넣을 숫자: ", i, j);
            scanf("%d", &bingo[i][j]);
        }
    }

    printf("\n------ 빙고판 완성! ------\n\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%3d ", bingo[i][j]);
        }
        printf("\n");
    }

    return 0;
}