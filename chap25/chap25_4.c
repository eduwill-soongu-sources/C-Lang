#include <stdio.h>

void hanoi(int n, char from, char by, char to) {
    if (n == 1) {
        printf("원반 1을 %c에서 %c로 옮긴다.\n", from, to);
    } else {
        hanoi(n - 1, from, to, by);
        printf("원반 %d(을)를 %c에서 %c로 옮긴다.\n", n, from, to);
        hanoi(n - 1, by, from, to);
    }
}

int main(void) {
    
    hanoi(3, 'A', 'B', 'C');
    return 0;
}