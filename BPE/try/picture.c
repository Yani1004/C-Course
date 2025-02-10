#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Picture{
    int code;
    char artist[31];
    char name[31];
    double price;
}Picture;

void readBinFile(char artist[]) {
    FILE *fp;
    Picture temp_pic;
    fp = fopen("picture.bin", "rb");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }
    int sizeArt, sizeName;
    while (fread(&temp_pic.code, sizeof(temp_pic.code), 1, fp) == 1 &&
           fread(&sizeArt, sizeof(sizeArt), 1, fp) == 1 &&
           fread(temp_pic.artist, sizeof(temp_pic.artist), sizeArt, fp) == sizeArt &&
           fread(&sizeName, sizeof(sizeName), 1, fp) == 1 &&
           fread(temp_pic.name, sizeof(temp_pic.name), sizeName, fp) == sizeName &&
           fread(&temp_pic.price, sizeof(temp_pic.price), 1, fp) == 1) {
        if (strcmp(temp_pic.artist, artist) == 0) {
            printf("Picture title: %s\n", temp_pic.name);
            printf("Price: %.2f BGN\n", temp_pic.price);
            printf("========================\n");
        }
    }
    if (ferror(fp)) {
        perror("Error: Failed reading from file");
        exit(1);
    }
    fclose(fp);
}

double aboveAveragePrice(Picture picture[],int size,double price){

    double averagePrice = 0;
    int found = 0;
    for(int i= 0;i<size;i++){
        if(picture[i].price>price){
            averagePrice+=picture[i].price;
            found++;
        }
    }
    if(found!=0){
        averagePrice/=found;
        return averagePrice;
    }else{
        return 0;
    }
}
int writeTxtFile(Picture picture[],int size,char letter){
    FILE * fp;
    fp = fopen("info.txt","a");
    if(fp==NULL){
        perror("Failed to open file!");
        exit(1);
    }
    int found = 0;
    for(int i = 0;i < size;i++){
        if(picture[i].name[0]==letter){
            if(fprintf(fp,"%d;%s;%.2lfleva\n",picture[i].code,picture[i].name,picture[i].price)<0){
                perror("Failed writing to file!");
                exit(1);
            }
            found++;
        }
    }
    fclose(fp);
    return found;
}

int main(){
    int n;
    do {
    printf("How many pictures are there? ");
    if (scanf("%d", &n) != 1) {
        perror("Failed reading data!");
        exit(1);
    }
} while (n <= 3 || n >= 30);

    Picture * picture = NULL;
    picture=(Picture*)calloc(n,sizeof(Picture));
    if(picture == NULL){
        perror("Failed to allocate memory!");
        exit(1);
    }
    for(int i = 0;i < n ; i++){
        printf("Enter code: ");
        if(scanf("%4d",&picture[i].code)<=0){
            perror("Failed reading data!");
            exit(1);
        }
        printf("Enter artist name: ");
        if(scanf("%s",picture[i].artist)<=0){
            perror("Failed reading data!");
            exit(1);
        }
        printf("Enter picture name: ");
        if(scanf("%s",picture[i].name)<=0){
            perror("Failed reading data!");
            exit(1);
        }
        printf("Enter price: ");
        if(scanf("%lf",&picture[i].price)<=0){
            perror("Failed reading data!");
            exit(1);
        }

    }
    double found = aboveAveragePrice(picture,n,40.6);
    printf("%.2f",found);
    free(picture);
    return 0;
}
