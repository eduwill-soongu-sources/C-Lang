#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int student_count;

    printf("성적을 입력할 학생 수 : ");
    scanf("%d", &student_count);
    
    // 학생 수만큼 배열의 공간을 할당
    int *scores = (int*) malloc(student_count * sizeof(int));

    if (scores == NULL) {
        printf("메모리가 할당되지 않았습니다!");
        return 1;
    }

    // 입력받기
    for (int i = 0; i < student_count; i++) {
        printf("%d번 학생의 성적: ", i + 1);
        scanf("%d", &scores[i]);
    }

    printf("\n==== 입력된 성적 ====\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d번 학생의 점수: %d점\n", i + 1, scores[i]);
    }

    printf("free전 scores의 주소: %p\n", scores);

    free(scores);
    scores = NULL;

    printf("free후 scores의 주소: %p\n", scores);
    
    return 0;
}