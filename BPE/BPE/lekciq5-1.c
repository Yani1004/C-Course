#include <stdio.h>

int main(){
    FILE *fp;
    char buff[20];
    int input;
    fp = fopen("myFile.txt","r");
    if(fp==NULL){
        exit(1);
    }
    //fprintf(fp,"Hello Banichka");
    //fgets(buff,20,fp);
    //printf("%s",buff);
    printf("Enter a number");
    scanf("%d",&input);
    fprintf(fp,"%d",input);
    fclose(fp);

    return 0;
}
