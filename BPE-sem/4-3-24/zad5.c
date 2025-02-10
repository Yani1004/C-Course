#include <stdio.h>

int main(){
    int n,m;
    printf("N:");
    scanf("%d",&n);
    printf("M:");
    scanf("%d",&m);
    int matrix[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            printf("matrix [%d][%d] - ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }
    //1 2 3 00 01 02
    //4 5 6 10 11 12
    //1 4   00 01
    //2 5   10 11
    //3 6   20 21
    return 0;
}
