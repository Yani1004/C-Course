#include <stdio.h>

int main(){
    int columns = 2;
    int rows = 2;
    int matrices = 2;
    //int *arr = malloc(columns*sizeof(int));
    int *cube = malloc(rows*columns*matrices*sizeof(int));
    for(int i = 0;i<columns*rows*matrices;i++){
        printf("%d ",*(cube+i));
        if(i%columns == columns - 1){
            printf("\n");
        }
        if(i%(columns*rows)== (columns*rows - 1)){
            printf("\n");
        }
    }
    printf("\n");
    for(int i = 0;i<columns*rows*matrices;i++){
        scanf("%d",cube+i);
    }
     for(int i = 0;i<columns*rows*matrices;i++){
        printf("%d ",*(cube+i));
        if(i%columns == columns - 1){
            printf("\n");
        }
        if(i%(columns*rows)== (columns*rows) - 1){
            printf("\n");
        }
    }
    printf("\n");
    free(cube);
    return 0;
}
