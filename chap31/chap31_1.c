#include <stdio.h>

// 배열을 반복해서 출력하는 함수
void print_scores(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    
    // 98 72 88 91 0 0 0 0 0 0
    int scores[10] = {98, 72, 88, 91};
    int count = 4; // 현재 저장된 실제 데이터 수

    printf("삽입 전: ");
    print_scores(scores, count);

    // 72와 88사이에 숫자 100을 중간에 삽입
    // 98 72 100 88 91
    int insert_data = 100;
    int insert_idx = 2;

    for (int i = count - 1; i >= insert_idx; i--) {
        scores[i + 1] = scores[i];
    }

    scores[insert_idx] = insert_data;

    count++;
    printf("삽입 후: ");
    print_scores(scores, count);

    return 0;
}