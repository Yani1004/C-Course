#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
void readWords(char words[]){
    FILE *fp;
    fp = fopen("input.txt","r");
    if(fp ==NULL){
        perror("Failed!");
        exit(1);
    }
    char prev = '\0';
    while(!feof(fp)){
        char temp[MAX];
        if(fscanf(fp,"%s",temp)!=0){

        }

    }

}
int main(){
    char *words = NULL;

    return 0;
}
