#include <stdio.h>

int main(){
    int columns = 5;
    int rows = 2;
    //int *arr = malloc(columns*sizeof(int));
    int *matrix = malloc(rows*columns*sizeof(int));
    for(int i = 0;i<columns*rows;i++){
        printf("%d ",*(matrix+i));
        if(i%columns == columns - 1){
            printf("\n");
        }
    }
    printf("\n");
    for(int i = 0;i<columns*rows;i++){
        scanf("%d",matrix+i);
    }
    for(int i = 0;i<columns*rows;i++){
       printf("%d ",*(matrix+i));
        if(i%columns == columns - 1){
            printf("\n");
        }
    }
    printf("\n");
    free(matrix);
    return 0;
}
