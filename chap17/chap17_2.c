#include <stdio.h>

int main(void) {
    
    int treasure_map[][3] = {
        {1,0,5}, 
        {0,20,0}
    }; 

    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("좌표 [%d][%d]의 보물: %d골드\n",
                 i, j, treasure_map[i][j]);
        }

        printf("----- 다음 행으로 이동 -----\n");
    }

    
    return 0;
}