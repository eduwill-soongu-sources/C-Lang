#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

int main(void) {
 
    int arr[] = {5, 1, 4, 2, 8};

    int i, j, min_index; // i : pass, j : swap, min_index: 최소인덱스

    // 배열 데이터 개수 구하기
    int len = sizeof(arr) / sizeof(int);

    for (i = 0; i < len - 1; i++) {

        // 최소 인덱스를 탐색하기 위해 자리뺏기를 시작
        min_index = i;

        for (j = i + 1; j < len; j++) {
            // 최소인덱스값보다 새로운 j가 작다고 판단되면
            if (arr[j] < arr[min_index]) {
                // 그 j를 최소인덱스로 갱신
                min_index = j;
            }
        }
        // 최소 인덱스 탐색이 끝난후 찾은 최소값과 현재 위치(i)의 값을 교환
        swap(&arr[i], &arr[min_index]);
    }


    // 출력
    printf("선택정렬 후: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}