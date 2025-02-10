#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float find_item(IceCream*, char, char);
unsigned char add_to_file(IceCream*, char, float, short);
void read_from_file(char );

typedef struct IceCream{
    char ID[2];
    char name[20];
    short weigth;
    float price; 
}IceCream;

int main(){
    
    IceCream *ice_cream_array;
    char n,i;
    do{
        printf("Please, enter a number betweeen 5 and 15!");
        scanf("%d", &n);

    }while(n<5 || n>=15);
    
    if(ice_cream_array=(IceCream*)malloc(n*sizeof(IceCream))==NULL){
        printf("Error");
        exit(1);
    
    }
    
    for(i=0;i<n;i++){
        printf("Please, enter id, name, weigth, price");
        scanf("%s %s %d %f", &ice_cream_array[i].ID, &ice_cream_array[i].name, &ice_cream_array[i].weigth, &ice_cream_array[i].price);

    }
    return 0;
}

float find_item(IceCream* arr_ptr, char count, char symbol){
  float total=0.0;
  char i;
  for(i=0;i<count;i++){
    if(arr_ptr[i].name[0]==symbol){
        total+=arr_ptr[i].price;
    }
  }
  return total;
}

unsigned char add_to_file(IceCream* arr_ptr, char count, float price, short weigth){
    char written_elements=0;
    char i;
    FILE *fp;

    if(fp=fopen("info.txt", "a")==NULL){
        printf("error opening file");
        exit(1);
    }

    for(i=0;i<count; i++){
      if((price>arr_ptr[i].price) && (weigth<arr_ptr[i].weigth)){
        fprintf(fp,"%s; %s; %d; %f leva", arr_ptr[i].ID, arr_ptr[i].name, arr_ptr[i].price, arr_ptr[i].price);
        written_elements++;
      }
    }

    fclose(fp);
    return written_elements;
}

void read_from_file(char ip_arg[2]){
    FILE* fp;
    IceCream temp;
    char temp_length;
    if(fp=fopen("IceCraem.bin", "rb")==NULL){
        printf("error opening file");
        exit(1);
    }

    while(!feof(fp)){
        if (fread(&temp.ID[0], sizeof(temp.ID),1,fp)!=1){
            printf("Reading error!");
            exit(1);
        }
        if(fread(&temp_length, sizeof(temp_length),1,fp)!=1){
            printf("Reading error!");
            exit(1);
        }
        if(fread(&temp.name, sizeof(char), temp_length,1,fp)!=temp_length){
            printf("Reading error!");
            exit(1);
        }
        if(fread(&temp.weigth, sizeof(temp.weigth),1,fp)!=1){
            printf("Reading error!");
            exit(1);
        }
        if(fread(&temp.price, sizeof(temp.price),1,fp)!=1){
            printf("Reading error!");
            exit(1);
        }
      if(0==strcmp(ip_arg,temp.ID)){
        printf("====================\n IceCream=%s\nPrice=%f BGN\n===================", temp.name, temp.price);
      }
    }

   close(fp);
}