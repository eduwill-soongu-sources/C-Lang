#include <stdio.h>

int main(void) {
 
    int arr[5] = {10, 20, 30, 40, 50};

    printf("대괄호 방식 접근: %d\n", arr[3]);
    printf("포인터 방식 접근: %d\n", *(arr + 3));

     printf("대괄호 방식 주소: %p\n", &arr[3]);
    printf("포인터 방식 주소: %p\n", arr + 3);

    return 0;
}