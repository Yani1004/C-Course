#include <stdio.h>
int *arrMemory(int columns){
    int *arr = malloc(columns*sizeof(int));
    if(arr==NULL){
        perror("error allocating memory");
        exit(1);
    }
    return arr;
}
void arrPrint(int *arr,int columns){
    for(int i = 0;i<columns;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void arrInit(int *arr,int columns){
    for(int i = 0;i<columns;i++){
        scanf("%d",&arr[i]);
    }
}
int main(){
    int columns = 5;
    int *arr = arrMemory(columns);
    arrPrint(arr,columns);
    arrInit(arr,columns);
    arrPrint(arr,columns);
    free(arr);
    return 0;
}
