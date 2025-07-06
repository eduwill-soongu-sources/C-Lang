#include <stdio.h>
#include <string.h>

int main(void) {
    
    char intro[50]; // 자기소개 저장

    printf("자기 소개를 한 줄 입력해주세요! ");

    // scanf("%s", intro);
    fgets(intro, 50, stdin);

    // 마지막 글자가 \n으로 되어있어서 의도치 않은 줄바꿈이 일어나므로
    // 마지막 글자를 \0로 수정
    intro[strlen(intro) - 1] = '\0';

    printf("\n--- 자기 소개 ---\n");
    printf("%s\n", intro);
    printf("============");

    return 0;
}