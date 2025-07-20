#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20]; // 이름
    char group[30]; // 그룹명
    int birth_year; // 출생년도
} IdolInfo;


int main(void) {

    IdolInfo* ptr_idol = (IdolInfo*) malloc(sizeof(IdolInfo));

    // 구조체 포인터로 작업
    // (*ptr_idol).name
    // ptr_idol->name

    strcpy(ptr_idol->name, "사쿠라");
    strcpy(ptr_idol->group, "르세라핌");
    ptr_idol->birth_year = 1998;

    printf("이름: %s\n", ptr_idol->name);
    printf("그룹명: %s\n", ptr_idol->group);
    printf("출생년도: %d\n", ptr_idol->birth_year);


    free(ptr_idol);
    
    return 0;
}