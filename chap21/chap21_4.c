#include <stdio.h>

int main(void) {
    
    int a = 30;
    int *p = &a;
    int **pp = &p;

    printf("## 값 접근 ##\n");
    printf("1. 일반변수로 접근: a = %d\n", a);
    printf("2. 포인터변수로 접근: p = %d\n", *p);
    printf("3. 이중 포인터변수로 접근: pp = %d\n", **pp);

    printf("## 주소값 접근 ##\n");
    printf("1. a의 주소: %p\n", &a);
    printf("2. p에 저장된 값: %p\n", p);
    printf("3. p의 주소: %p\n", &p);
    printf("4. pp에 저장된 값: %p\n", pp);

    **pp = 500;

    printf("a = %d\n", a);

    return 0;
}   