#include <stdio.h>

int main() {
    char symbol;
    printf("Type in the symbol: ");
    scanf("%c",&symbol);

    for (int i = 1; i <= 5; i++) {
        for (int j = i; j < 5; j++) {
            printf(" ");
        }
        if (i == 1 || i == 5) {
            for (int j = 1; j <= i * 2 - 1; j++) {
                printf("%c",symbol);
            }
        } else {
            printf("%c",symbol);
            for (int j = 1; j <= (i - 1) * 2 - 1; j++) {
                printf(" ");
            }
            printf("%c",symbol);
        }
        printf("\n");
    }

    return 0;
}

