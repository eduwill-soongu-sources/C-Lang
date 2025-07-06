#include <stdio.h>
#include <string.h>

int main(void) {
 
    char origin[] = "apple";
    char copy[3];

    // copy = origin;
    strcpy(copy, origin);

    printf("원본: %s\n", origin);
    printf("사본: %s\n", copy);

    return 0;
}