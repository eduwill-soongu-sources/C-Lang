#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a= *b;
    *b = t;
}

// 파티션 함수 만들기
// 피벗을 기준으로 작은 값들은 왼쩍, 큰 값들은 오른쪽으로 재배치
// 최종적으로 확정된 피벗의 인덱스를 반환한다.
                //  분할시작인덱스, 분할끝인덱스
int partition(int arr[], int low, int high) {
 
    // 피벗값을 설정 - 배열의 마지막값을 피벗으로 가정
    int pivot = arr[high];
    // 감독관 설정 - 첫 위치가 -1 인덱스를 가리키게함
    int i = (low - 1);

    // 탐험가 j가 low부터 피벗 바로 앞까지 순회
    for (int j = low; j <= high - 1; j++) {
        // j가 가리키는 값이 피벗보다 작거나 같으면
        if (arr[j] <= pivot) {
            i++; // 감독관이 앞으로 한 칸 이동
            swap(&arr[i], &arr[j]);
        }
    }
    // 모든 탐험이 끝난 후 감독관의 자리를 한칸 이동시키고 피벗과 값 교환
    i++;
    swap(&arr[i], &arr[high]);

    // 피벗의 최종 인덱스 (위치) 반환
    return i;
}

// 퀵 정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// 배열 출력 함수
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void) {

    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("주어진 배열: \n");
    printArray(arr, len);

    // 퀵정렬 진행
    quickSort(arr, 0, len - 1);

    printf("\n정렬된 배열: \n");
    printArray(arr, len);
    
    return 0;
}