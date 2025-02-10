#include <stdio.h>

void findSum(int nums[], int n, int sum) {
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = i; j < n; j++) {
            temp += nums[j];
            if (temp == sum) {
                for(int k = i;k<=j;k++){
                    printf("%d ",nums[k]);
                }
                return;
            }
        }
    }
    printf("No sequence found !\n");
}

int main() {
    int n;
    printf("Enter the length: ");
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        int temp;
        printf("N%d: ", i + 1);
        scanf("%d", &temp);
        nums[i] = temp;
    }
    int sum;
    printf("Enter the sum: ");
    scanf("%d", &sum);
    findSum(nums, n, sum);
    return 0;
}
