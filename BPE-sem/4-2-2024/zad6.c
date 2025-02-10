#include <stdio.h>

void findBigger(int num[], int n) {
    int max = 1;
    int start = 0;
    for (int i = 0; i < n; i++) {
        int counter = 1;
        for (int j = i; j < n - 1; j++) {
            if (num[j]<num[j + 1]) {
                counter++;
            } else {
                break;
            }
        }
        if (counter > max) {
            max = counter;
            start = i;
        }
    }
    for (int k = start; k < (start + max); k++) {
        printf("%d ", num[k]);
    }
    printf("\n");
}

void findSmaller(int num[], int n) {
    int max = 1;
    int start = 0;
    for (int i = 0; i < n; i++) {
        int counter = 1;
        for (int j = i; j < n - 1; j++) {
            if (num[j]>num[j + 1]) {
                counter++;
            } else {
                break;
            }
        }
        if (counter > max) {
            max = counter;
            start = i;
        }
    }
    for (int k = start; k < (start + max); k++) {
        printf("%d ", num[k]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the length: ");
    scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; i++) {
        int temp;
        printf("N%d: ", i + 1);
        scanf("%d", &temp);
        nums[i] = temp;
    }
    findBigger(nums,n);
    findSmaller(nums,n);
    return 0;
}
