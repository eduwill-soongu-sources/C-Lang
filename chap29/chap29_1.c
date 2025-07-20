#include <stdio.h>


// 선형 탐색 수행 함수
int linearSearch(int arr[], int n, int target) {
    // 배열을 처음부터 끝까지 순회
    for (int i = 0; i < n; i++) {
        printf("반복문 실행 %d회차\n", i + 1);
        if (arr[i] == target) {
            // 찾았으면 해당 시점의 i를 리턴
            return i;
        }
    }
    return -1; // 못찾았을 때 -1을 리턴
}

int main(void) {
 
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(data) / sizeof(data[0]);
    int target_value = 11; // 찾고싶은 값

    int index = linearSearch(data, size, target_value);

    if (index == -1) {
        printf("%d 값은 배열에 없습니다.\n", target_value);
    } else {
        printf("%d 값은 배열의 %d번 인덱스에 있습니다.\n", target_value, index);
    }

    return 0;
}