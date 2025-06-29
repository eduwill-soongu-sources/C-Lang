#include <stdio.h>

int main(void) {
    
    // 변수 선언
    int my_age;
    float my_height;
    char my_initial;

    // 변수 값 할당
    my_age = 25;
    my_height = 180.5;
    my_initial = 'H'; // 한글자는 ''를 쓴다.

    // 변수의 선언과동시에 할당
    int money = 10000;

    printf("제 나이는 %d살입니다.\n", my_age);

    // %f: 소수점 6자리까지 표현 강제
    printf("제 키는 %.1fcm입니다.\n", my_height);

    printf("제 이니셜은 %c입니다.\n", my_initial);

    int score1 = 100;
    int score2 = 8;

    printf("점수1: %5d점\n", score1);
    printf("점수2: %5d점\n", score2);

    return 0;
}