#include <stdio.h>

int main(void) {
    
    int choice;
    printf("최애 걸그룹은? (1: 에스파, 2: 아이브, 3: 르세라핌): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("에스파!! 이위위위윕플래시!\n");
            break;
        case 2:
            printf("아이브!! 숨참고 러브다이브!\n");
            break;
        case 3:
            printf("르세라핌!! ANTITITI FRAGILE!\n");
            break;
        default:
            printf("K-pop 화이팅!\n");
    }

    return 0;
}