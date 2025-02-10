#include <stdio.h>
#include <stdlib.h>

int writeBinFile(char file_name[]) {
    int count;
    char name[30];
    double grade;

    FILE *fp = fopen(file_name, "wb");
    if (fp == NULL) {
        perror("Error on opening bin file in write mode.");
        exit(1);
    }

    printf("How many students will you enter: ");
    scanf("%d", &count);
    fwrite(&count, sizeof(count), 1, fp);
    for (int i = 1; i <= count; i++) { // Changed loop conditions
        printf("Student's name and grade: ");
        scanf("%s %lf", name, &grade);
        fwrite(name, sizeof(name), 1, fp);
        fwrite(&grade, sizeof(grade), 1, fp);
    }

    fclose(fp);
    return 0;
}

int readBinFile(char file_name[]) {
    int count;
    char name[30];
    double grade;
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        perror("Error on opening bin file in read mode.");
        exit(2);
    }
    fread(&count, sizeof(count), 1, fp);
    printf("Students count: %d\n", count);
    for (int i = 1; i <= count; i++) {
        fread(name, sizeof(name), 1, fp);
        fread(&grade, sizeof(grade), 1, fp);
        printf("Student %d: %s %.2f\n", i, name, grade);
    }

    fclose(fp);
    return 0;
}
int deleteBinFile(char file_name[]){
    int error = remove(file_name);
    if(error){
        printf("File could not be deleted");
        return error;
    }
    return 0;
}
int main() {
    //writeBinFile("students.bin");
    readBinFile("students.bin");
    deleteBinFile("students.bin");
    return 0;
}
