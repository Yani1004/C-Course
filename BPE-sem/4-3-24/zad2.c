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
    printf("\nGlaven Diagonal\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i == j){
                printf("%d ",matrix[i][j]);
            }
        }
    }
    printf("\nElementi nad glaven diagonal:\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i < j){
                printf("%d ",matrix[i][j]);
            }
        }
    }
    //1 2 3 00 01 02
    //4 5 6 10 11 12
    //7 8 9 20 21 22
    //1 5 9
    return 0;
}
