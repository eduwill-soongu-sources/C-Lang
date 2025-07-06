#include <stdio.h>
#include <string.h>

int main(void) {
    
    char origin[] = "strawberry";
    char copy[6];

    strncpy(copy, origin, 5);

    // strncpy는 널문자는 복사해오지 않음...
    // 안전한 처리를 위해 마지막 칸에 수동으로 널문자를 넣어줌
    copy[5] = '\0';

    printf("안전하게 복사된 문자열: %s\n", copy);

    return 0;
}