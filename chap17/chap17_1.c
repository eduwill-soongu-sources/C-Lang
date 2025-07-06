#include <stdio.h>

int main(void) {
    
    // 3행 4열짜리 미니맵
    int mini_map[3][4];

    // 값을 할당
    mini_map[1][2] = 10;
    
    // 값을 참조
    printf("지도 [1][2]의 정보: %d\n", mini_map[1][2]);
    
    return 0;
}