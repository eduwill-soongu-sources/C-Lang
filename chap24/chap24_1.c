#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

int main(void) {
 
    int arr[] = {5, 1, 4, 2, 8};

    int i, j; // i : pass, j : swap

    // 배열 데이터 개수 구하기
    int len = sizeof(arr) / sizeof(int);

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }


    // 출력
    printf("버블정렬 후: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}