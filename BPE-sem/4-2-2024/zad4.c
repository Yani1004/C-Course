#include <stdio.h>
void mover(int nums[], int n, int k) {
    //1 2 3 4 5
    //0 1 2 3 4

    //4 5 1 2 3
    //0 1 2 3 4

    //n=5 k=2
    //n-k = 3
    int temp[n];
    for (int i = 0; i < n; i++) {
        if (i < (n - k)) {
            temp[i + k] = nums[i];
        } else {
            temp[i -(n - k)] = nums[i];
        }
    }
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}
int main(){
    int n,k;
    printf("Enter the length: ");
    scanf("%d", &n);
    int nums[n];
    for(int i = 0; i < n; i++) {
        int temp;
        printf("N%d: ", i + 1);
        scanf("%d", &temp);
        nums[i] = temp;
    }
    printf("Enter the steps: ");
    scanf("%d", &k);
    for(int i = 0;i<n;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    mover(nums,n,k);
    for(int i = 0;i<n;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}
