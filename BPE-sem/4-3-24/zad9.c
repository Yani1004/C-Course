#include <stdio.h>

int main(){
    int flat[3][2][2];
     for(int i = 0;i < 3;i++){
        for(int j = 0;j < 2;j++){
            for(int k = 0;k<2;k++){
                printf("flat [%d][%d][%d] - ",i,j,k);
                scanf("%d",&flat[i][j][k]);
            }
        }
     }
    int sum = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<2;j++){
            for(int k = 0;k<2;k++){
                printf("%d ", flat[i][j][k]);
                sum+=flat[i][j][k];
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("The sum is %d",sum);

}
