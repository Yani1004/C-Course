    #include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 31
typedef struct Picture{
    int code;
    char artist_name[LENGTH];
    char picture_name[LENGTH];
    double price;
}Picture;
double averageAbovePrice(Picture pictures[],int n,double price){
    if(n<0){
        printf("Invalid!");
        return -1;
    }
    double average = 0;
    int count = 0;
    for(int i = 0;i<n;i++){
        if(pictures[i].price>price){
            count++;
            average+=pictures[i].price;
        }
    }
    if(count == 0){
        return count;
    }else{
        average /=count;
        return average;
    }
}

int writeToTxtFile(Picture pictures[],int n,char letter){
    FILE * fp;
    fp = fopen("info.txt","w");
    if(fp == NULL){
        perror("Failed to open the file");
        return -1;
    }
    int count = 0;
    for(int i = 0;i<n;i++){
        if(pictures[i].artist_name[0]==letter){
            fprintf(fp,"%d;%s;%lfleva\n",pictures[i].code,pictures[i].picture_name,pictures[i].price);
            count++;
        }
    }
    fclose(fp);
    return count;
}
void printFromBin(char artist[]){
    FILE * fp;
    fp = fopen("picture.bin","rb");
    if(fp == NULL){
        perror("Cannot open file!");
        return;
    }
    int code,length_artist,length_name;
    while(fread(&code,sizeof(int),1,fp)==1){
        if(fread(&length_artist,sizeof(int),1,fp)!=1){
            perror("Cannot read from file!");
            fclose(fp);
            return;
        }
        char artist_name[length_artist];
        if(fread(artist_name,sizeof(char),length_artist,fp)!=length_artist){
            perror("Cannot read from file!");
            fclose(fp);
            return;
        }
        if(fread(&length_name,sizeof(int),1,fp)!=1){
            perror("Cannot read from file!");
            fclose(fp);
            return;
        }
        char picture_name[length_name];
        if(fread(picture_name,sizeof(char),length_name,fp)!=length_name){
            perror("Cannot read from file!");
            fclose(fp);
            return;
        }
        double price;
        if(fread(&price,sizeof(double),1,fp)!=1){
            perror("Cannot read from file!");
            fclose(fp);
            return;
        }
        if(strcmp(artist_name,artist)==0){
            printf("Picture title: %s \nPrice: %.2lf BGN\n======================",picture_name,price);

        }
    }
    fclose(fp);
}
int main(){
    Picture * pictures = NULL;
    int n=sizeof(pictures)/pictures[0];
    printf("%ld",n);
    printf("Type in the number of elements: ");
    scanf("%d",&n);
    while(n<=3||n>=30){
        printf("Type in the number of elements: ");
        scanf("%d",&n);
    }
    pictures = (Picture*)calloc(n,sizeof(Picture));
    if(pictures==NULL){
        perror("Failed to allocate memory!");
        return 1;
    }
    for(int i = 0;i<n;i++){
        printf("Code: ");
        scanf("%d",&pictures[i].code);
        printf("Artist: ");
        scanf("%s",pictures[i].artist_name);
        printf("Picture: ");
        scanf("%s",pictures[i].picture_name);
        printf("Price: ");
        scanf("%lf",&pictures[i].price);
    }
    free(pictures);


}
