#include <stdio.h>
int writeToFile(char file_name[]){
    int count;
    char name[30];
    double grade;

    FILE * fp=fopen(file_name,"wt");
    if(fp == NULL){
        perror("Error on opening txt file in write mode.");
        exit(1);
    }
    printf("How many students will you enter: ");
    scanf("%d",&count);
    printf("Students name and grade: ");
    scanf("%s %lf",name,&grade);
    fprintf(fp,"%s %.2f",name,grade);
    for(int i = 2;i<=count;i++){
        printf("Students name and grade: ");
        scanf("%s %lf",name,&grade);
        fprintf(fp,"\n%s %.2f",name,grade);
    }
    fclose(fp);
    return 0;
}

int appendToFile(char file_name[]){
    char name[30];
    double grade;

    FILE * fp=fopen(file_name,"at");
    if(fp == NULL){
        perror("Error on opening txt file in write mode.");
        exit(1);
    }
    printf("Students name and grade: ");
    scanf("%s %lf",name,&grade);
    fprintf(fp,"\n%s %.2f",name,grade);

    fclose(fp);
    return 0;
}
int readTxtFile(char file_name[]) {
    char name[30];
    double grade;
    FILE *fp = fopen(file_name, "rt");
    if (fp == NULL) {
        perror("Error on opening txt file in read mode.");
        exit(2);
    }
    while (!feof(fp)) {
        fscanf(fp,"%s %lf",name,&grade);
        printf("%s %.2f\n", name, grade);
    }
    fclose(fp);
    return 0;
}

int main(){
    //writeToFile("students.txt");
    appendToFile("students.txt");
    readTxtFile("students.txt");
    int error=readTxtFile("students.txt");
    if(error!= 0){
        exit("error");
    }
    return 0;
}
