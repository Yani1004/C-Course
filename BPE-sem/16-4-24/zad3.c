#include <stdio.h>

int main(){
    int n,m;
    printf("N: ");
    scanf("%d",&n);
    printf("M: ");
    scanf("%d",&m);
    int matrix[n][m];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("Matrix [%d][%d]",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    if(n<3 ||m<3){
        printf("No such array");
    }else if(n == 3 && m == 3){
        int sum = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
            sum+=matrix[i][j];
            }
        }
        printf("Sum = %d",sum);
    }else{
        int maxSum =0;
        int maxSumR = 0,maxSumC = 0;
        for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            // Calculate sum of current 3 by 3 subarray
            int sum = 0;
            for (int p = i; p < i + 3; p++) {
                for (int q = j; q < j + 3; q++) {
                    sum += matrix[p][q];
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxSumR = i;
                maxSumC = j;
            }
        }
        }
        printf("Maximum sum subarray (3x3):\n");
        for (int i = maxSumR; i < maxSumR + 3; i++) {
            for (int j = maxSumC; j < maxSumC + 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Maximum sum: %d\n", maxSum);
    }



}
