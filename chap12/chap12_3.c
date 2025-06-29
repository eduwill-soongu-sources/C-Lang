#include <stdio.h>

int main(void) {
    
    printf("당신의 나이를 입력하세요: ");

    // 나이를 저장할 변수
    int my_age;
    // 키를 저장할 변수
    float my_height;

    scanf("%d", &my_age);
    

    printf("당신의 키를 입력하세요: ");
    scanf("%f", &my_height);

    printf("입력하신 나이는 %d살이고 키는 %.1fcm이군요!\n", my_age, my_height);

    return 0;
}