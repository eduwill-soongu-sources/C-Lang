#include <stdio.h>

int main(void) {
 
    int arr[] = {5, 1, 4, 2, 8};

    int i, j, key; // i : pass, j : swap, key: 삽입대상 데이터를 백업

    // 배열 데이터 개수 구하기
    int len = sizeof(arr) / sizeof(int);

    for (i = 1; i < len; i++) {

        // 카드를 한장 뽑아서 백업
        key = arr[i];

        // 왼쪽을 확인하면서 자기보다 크면 오른쪽으로 한칸 이동시킴
        // 자기보다 작으면 그자리로 지가 삽입됨
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            // 값을 뒤로 한칸 밀어버림
            arr[j + 1] = arr[j];
        }
        // 반복문이 멈췄을 때 멈춘 자리로 KEY를 삽입
        arr[j + 1] = key;
    }


    // 출력
    printf("삽입정렬 후: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}