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
            do{
                printf("matrix [%d][%d] - ",i,j);
                scanf("%d",&matrix[i][j]);
            }while(matrix[i][j]<2||matrix[i][j]>6);
        }
    }
     for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(matrix[i][j]!=6){
                matrix[i][j]++;
            }
        }
    }
   for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            printf("%d ",matrix[i][j]);
        }
    }

    return 0;
}
