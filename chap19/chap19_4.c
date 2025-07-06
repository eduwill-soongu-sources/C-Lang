#include <stdio.h>
#include <string.h>

int main(void) {
    
    char password[] = "pass1234"; // 초기 비밀번호
    char input[20]; // 사용자가 입력할 비밀번호

    printf("비밀번호를 입력하세요: ");
    scanf("%s", input);

    if (strcmp(password, input) == 0) {
        printf("로그인 성공!!\n");
    } else {
        printf("비밀번호가 틀렸습니다.!\n");
    }

    return 0;
}