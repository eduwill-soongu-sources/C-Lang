#include <stdio.h>

int main(void) {
    
    int a = 10;
    int *p;  // 포인터변수
    p = &a;

    printf("a의 주소: %p\n", &a);
    printf("p의 값: %p\n", p);

    printf("포인터 p로 찾아간 곳의 값: %d\n", *p);

    return 0;
}