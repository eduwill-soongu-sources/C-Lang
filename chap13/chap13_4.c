
#include <stdio.h>

int main(void) {
    int lol_point = 950;

    if (lol_point >= 1000) {
        printf("당신은 마스터 이상! 폼 미쳤다\n");
    }
    else if (lol_point >= 500) {
        printf("당신은 다이아! 재능 있으시네요\n");
    } 
    else {
        printf("당신은 플래티넘 이하! 힘내세요\n");
    }
    return 0;
}