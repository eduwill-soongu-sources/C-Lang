#include <stdio.h>

int main(void) {
 
    int level;
    int total_exp = 0;

    for (level = 1; level <= 10; level++) {
        printf("%d레벨 달성! 경험치 %d획득!\n", level, level);
        total_exp += level; // total_exp = total_exp + level;
    }

    printf("\n>> 총 획득 경험치: %d\n", total_exp);

    return 0;
}