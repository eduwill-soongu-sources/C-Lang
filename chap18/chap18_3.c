#include <stdio.h>

int main(void) {
 
    // char fruit[] = "apple";
    char fruit[] = {'a', 'p', 'p', 'l', 'e', '\0'};

    int i = 0;
    int count = 0;
    while (fruit[i] != '\0') {
        printf("%c", fruit[i]);
        i++;
        count++;
    }
    printf("\n단어 %s의 길이는 %d입니다.\n", fruit, count);

    return 0;
}