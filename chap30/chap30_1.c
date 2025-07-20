#include <stdio.h>
#include <string.h>

// 아이돌의 설계도
// struct Idol {
//     char name[20]; // 이름
//     char group[30]; // 그룹명
//     int birth_year; // 출생년도
// };

// typedef 사용
// typedef struct Idol IdolInfo;


// 구조체를 만들면서 typedef를 바로 선언해두기
typedef struct {
    char name[20]; // 이름
    char group[30]; // 그룹명
    int birth_year; // 출생년도
} IdolInfo;

int main(void) {

    // 구조체 변수를 만들면
    // 이순간 메모리에 yujin이라는 이름으로 name, group, birth_year가 생성된다
    // struct Idol yujin = {"안유진", "IVE", 2003};

    IdolInfo chaewon = {"김채원", "르세라핌", 2000};
    IdolInfo wonyoung = {"장원영", "아이브", 2004};

    // 구조체의 변수에 접근 . 을 사용
    // strcpy(yujin.name, "안유진");
    // strcpy(yujin.group, "아이브");
    // yujin.birth_year = 2003;

    // 참조
    printf("이름: %s\n", chaewon.name);
    printf("그룹명: %s\n", chaewon.group);
    printf("출생년도: %d\n", chaewon.birth_year);

    printf("\n이름: %s\n", wonyoung.name);
    printf("그룹명: %s\n", wonyoung.group);
    printf("출생년도: %d\n", wonyoung.birth_year);
    
    return 0;
}   