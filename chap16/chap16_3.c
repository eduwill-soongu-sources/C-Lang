#include <stdio.h>

int main(void) {
 
    int scores[5];

    int i;
    for (i = 0; i < 5; i++) {
        printf("%d번 학생의 성적을 입력: ", i + 1);
        scanf("%d", &scores[i]);
    }

    printf("\n----- 성적 입력 완료 -----\n");
    for (i = 0; i < 5; i++) {
        printf("%d번 학생 점수: %d\n", (i + 1), scores[i]);
    }

    return 0;
}