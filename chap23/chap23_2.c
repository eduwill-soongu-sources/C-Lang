#include <stdio.h>

void doubleElements(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) *= 2;
    }
}

int main(void) {
 
    int nums[5] = {1, 2, 3, 4, 5};

    doubleElements(nums, 5);


    for (int i = 0; i  < 5; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}