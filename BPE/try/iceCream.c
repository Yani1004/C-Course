#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_CODE 3
#define LEN_NAME 21

typedef struct IceCream {
    char code[LEN_CODE];
    char name[LEN_NAME];
    int weight;
    float price_per_kilo;
} IceCream;

float findIceCream(IceCream ice_cream_arr[],int n,char letter){
    float sum_price = 0;
    for(int i = 0;i<n;i++){
        if(ice_cream_arr[i].name[0]==letter){
            sum_price+=ice_cream_arr[i].price_per_kilo;
        }
    }
    return sum_price;
}
int writeToFile(IceCream ice_cream_arr[],int n,float price,int weight){
    FILE *fp;
    int countWritten=0;
    fp = fopen("info.txt","wt");
    if(fp==NULL){
        perror("Error on opening txt file in write mode.");
        exit(1);
    }

    for(int i = 0;i<n;i++){
        if(ice_cream_arr[i].price_per_kilo<price && ice_cream_arr[i].weight >weight){
            fprintf(fp,"%s;%s;%d,%.2fleva",ice_cream_arr[i].code,ice_cream_arr[i].name,ice_cream_arr[i].weight,ice_cream_arr[i].price_per_kilo);
            countWritten++;
        }

    }
    fclose(fp);
    return countWritten;
}

void readFromBin(char code[]){
    FILE *fp;
    fp = fopen("icecream.bin","rb");
    IceCream temp;
    char temp_length;
    if (fp == NULL) {
        perror("Error on opening bin file in read mode.");
        exit(2);
    }
    while(!feof(fp)){
        if(fread(&temp.code[0],sizeof(temp.code),1,fp)!=1){
            perror("Reading error");
            exit(1);
        }
        if(fread(&temp_length,sizeof(temp_length),1,fp)!=1){
            perror("Reading error");
            exit(1);
        }
        if(fread(&temp.name,sizeof(temp_length),1,fp)!=temp_length){
            perror("Reading error");
            exit(1);
        }
        if(fread(&temp.weight,sizeof(temp.weight),1,fp)!=1){
            perror("Reading error");
            exit(1);
        }
        if(fread(&temp.price_per_kilo,sizeof(temp.price_per_kilo),1,fp)!=1){
            perror("Reading error");
            exit(1);
        }
        if(0==strcmp(code,temp.code)){
            printf("====================\n IceCream=%s\nPrice=%f BGN\n===================", temp.name, temp.price_per_kilo);
        }

    }
}
int main() {
    int n;
    IceCream *ice_cream_arr;

    do {
        printf("How many elements would you like to create? (6 - 14) => ");
        scanf("%d", &n);
    } while (n <= 1 || n >= 15);

    ice_cream_arr = (IceCream*)malloc(n * sizeof(IceCream));
    if (ice_cream_arr == NULL) {
        perror("Could not allocate memory!");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d",i);
        char code[LEN_CODE];
        char name[LEN_NAME];
        printf("Ice cream code: ");
        scanf("%s", code);
        strcpy(ice_cream_arr[i].code,code);

        printf("Ice cream Name: ");
        scanf(" %[^\n]",name);
        strcpy(ice_cream_arr[i].name,name);

        printf("Ice cream weight: ");
        scanf("%d", &ice_cream_arr[i].weight);

        printf("Ice cream price per kilo: ");
        scanf("%f", &ice_cream_arr[i].price_per_kilo);
        printf("\n");
    }

    char letter;
    printf("Letter search: ");
    scanf(" %c",&letter);
    float result = findIceCream(ice_cream_arr,n,letter);
    printf("%.2f",result);
    free(ice_cream_arr);
    return 0;
}
