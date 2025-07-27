#include <stdio.h>

// 배열을 반복해서 출력하는 함수
void print_scores(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    
    // 98 72 88 91 100  0 0 0 0 0
    int scores[10] = {98, 72, 100, 88, 91};
    int count = 5; // 현재 저장된 실제 데이터 수

    printf("삭제 전: ");
    print_scores(scores, count);

    // 삭제인덱스
    int del_idx = 2;

    for (int i = del_idx; i < count - 1; i++) {
        scores[i] = scores[i + 1];
    }

    count--;
    printf("삭제 후: ");
    print_scores(scores, count);

    return 0;
}