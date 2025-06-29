#include <stdio.h>

int main(void) {

    int level;
    int line;

    for (level = 2; level <= 9; level++) {
        // 구구단 level단 출력
        printf("===== 구구단 %d단 =====\n", level);

        for (line = 1; line <= 9; line++) {
            printf("# %d x %d = %d\n", level, line, level * line);
        }

    }

    return 0;
}