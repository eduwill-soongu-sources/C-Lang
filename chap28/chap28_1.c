#include <stdio.h>
#include <stdlib.h>

// 병합 알고리즘 (두개의 부분 배열을 합쳐나가면서 정렬)
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    // left: 0, right: 7, mid: 3
    int n1 = mid - left + 1; // 왼쪽 배열 부분의 크기
    int n2 = right - mid;    // 오른쪽 배열 부분의 크기

    // 임시 배열 (분할된 두개의 그룹을 의미) - 동적할당으로 배열 생성
    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    // 원본배열에서 임시배열로 데이터 복사
    // [ 7, 2, 6, 4, 5, 8, 3, 6 ]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // 병합 로직 - 2개의 부분배열 (L, R)의 데이터를 하나씩 비교해서 
    // 작은 녀석을 병합배열에 쌓기
    // L : [7, 2, 6, 4] || R : [5, 8, 3, 6]
    i = 0;    // L배열의 시작인덱스
    j = 0;    // R배열의 시작인덱스
    k = left; // 병합배열의 시작인덱스

    // L배열의 끝인덱스, R배열의 끝인덱스
    // 왼쪽 오른쪽 중에 한쪽이라도 끝에 도달하면 반복문 종료
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 한쪽 배열에 데이터가 남아있는 상태라면, 그대로 순서대로 뒤에 붙임
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // 임시 배열의 메모리 해제
    free(L);
    free(R);

}

// 병합 알고리즘 메인 함수
void mergeSort(int arr[], int left, int right) {
    // 재귀 종료 조건 : 쪼갤 배열의 크기가 1이 되면 멈춤
    if (left < right) {
        // 중간인덱스 구하기
        //  left - 0, right - 7, mid = 3
        //  left - 4, right - 7, mid = 5
        int mid = left + (right - left) / 2;

        // 왼쪽 절반에 대해서 재귀호출을 통해 쪼개기
        mergeSort(arr, left, mid);
        // 오른쪽 절반에 대해서 재귀호출을 통해 쪼개기
        mergeSort(arr, mid + 1, right);
        // 병합 발동
        merge(arr, left, mid, right);
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

    int arr[] = { 38, 27, 43, 3, 9, 82, 10, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("주어진 배열: \n");
    printArray(arr, len);

    // 병합정렬 진행
    mergeSort(arr, 0, len - 1);

    printf("\n정렬된 배열: \n");
    printArray(arr, len);
    
    return 0;
}