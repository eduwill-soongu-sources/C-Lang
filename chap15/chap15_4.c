#include <stdio.h>

int main(void) {
 
    int answer = 59; // 컴퓨터가 숨긴 숫자
    int guess = 0; // 사용자가 추측한숫자
    int try_count = 0; // 시도한 횟수

    while (guess != answer) {
        printf("숫자를 입력하세요 (1~100): ");
        scanf("%d", &guess);
        try_count++;

        if (guess > answer) {
            printf("DOWN!!\n");
        } else {
            printf("UP!!\n");
        }
    }

    printf("\n정답입니다! %d번만에 맞추셨네요!\n", try_count);

    return 0;
}