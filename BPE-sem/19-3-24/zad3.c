#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x, max_num = 0, min_num = 0, first_input = 1;

    printf("Enter numbers (0 to stop):\n");

    while (1) {
        printf("Number: ");
        scanf("%d", &x);

        if (x == 0) {
            break;
        }

        if (first_input) {
            max_num = x;
            min_num = x;
            first_input = 0;
        } else {
            max_num = max(max_num, x);
            min_num = min(min_num, x);
        }
    }

    if (first_input) {
        printf("No numbers entered.\n");
    } else {
        printf("Maximum number entered: %d\n", max_num);
        printf("Minimum number entered: %d\n", min_num);
    }

    return 0;
}
