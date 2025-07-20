#include <stdio.h>

typedef struct {
    char name[20]; // 이름
    char group[30]; // 그룹명
    int birth_year; // 출생년도
} IdolInfo;

// 아이돌 정보 출력함수 (call by value)
void printIdolInfoV1(IdolInfo idol) {
    printf("---- 아이돌 정보 (구조체 전체 전달) ----\n");
    printf("이름: %s\n", idol.name);
    printf("그룹명: %s\n", idol.group);

    idol.birth_year = 3000;
    printf("출생년도: %d\n", idol.birth_year);
}

// 아이돌 정보 출력함수 (call by reference)
void printIdolInfoV2(IdolInfo* idol) {
    printf("---- 아이돌 정보 (구조체 포인터 전달) ----\n");
    printf("이름: %s\n", idol->name);
    printf("그룹명: %s\n", idol->group);

    idol->birth_year = 3000;
    printf("출생년도: %d\n", idol->birth_year);
}


int main(void) {

    IdolInfo karina = {"카리나", "에스파", 2000};

    // printIdolInfoV1(karina);

    printIdolInfoV2(&karina);

    printf("함수종료후 출생년도: %d\n", karina.birth_year);
    
    return 0;
}