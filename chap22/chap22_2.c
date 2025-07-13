#include <stdio.h>

int main(void) {
    
    int arr[5] = {10, 20, 30, 40, 50};
    
    printf("arr[0]의 주소: %p\n", &arr[0]);
    printf("arr[1]의 주소: %p\n", &arr[1]);
    printf("arr[2]의 주소: %p\n", &arr[2]);
    printf("\n");

    printf("arr의 주소: %p\n", arr);
    printf("arr + 1의 주소: %p\n", arr + 1);
    printf("arr + 2의 주소: %p\n", arr + 2);

    return 0;
}