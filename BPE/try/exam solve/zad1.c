#include <stdio.h>
#define LEN 31
#define LEN_C 8
typedef struct Pets{
    char name[LEN];
    char chip[LEN_C];
    float price;

}Pets;

Pets create_write(){
    FILE * fp;
    Pets pet;

    fp = fopen("animalsText.txt","w");
    if (fp == NULL) {
        perror("Error opening file!\n");
        return pet;
    }

    printf("Name of pet: ");
    scanf("%s",pet.name);
    printf("Chip: ");
    scanf("%s",pet.chip);
    printf("Price: ");
    scanf("%f",&pet.price);
    //printf("%s %s %.2f",pet.name,pet.chip,pet.price);
    fprintf(fp,"%s, %.2f\n",pet.name,pet.price);

    fclose(fp);

    return pet;
}
void findPetByPrice(Pets pets[],int size,float price){
    int found = 0;
    for(int i=0;i<size;i++){
        if(pets[i].price == price){
            printf("%s - %s",pets[i].name,pets[i].chip);
            found = 1;
        }
    }
    if(found == 0){
        printf("No matches found!");
    }
}
void findAndPrintBin(float price){
    FILE *fp;
    Pets pet;
    fp = fopen("animalsBin.bin","rb");

    if (fp == NULL) {
        perror("Error opening file!\n");
    }

    while(fread(&pet,sizeof(Pets),1,fp)==1){
        if(pet.price >=price){
            printf("Bin OwnerName: %s\n",pet.name);
            printf("Bin Chip: %s\n",pet.chip);
            printf("Bin Price: %.2f\n",pet.price);
            printf("-----------\n");
        }
    }
     if (!feof(fp)) {
        perror("Error reading from file!\n");
     }
    fclose(fp);
}
int main(){
    Pets pets[LEN];
    /*int index = 0;
    pets[index++]= create_write();
    pets[index++]= create_write();
    pets[index++]= create_write();
    pets[index]= create_write();
    findPetByPrice(pets,index,10.00);*/
    findAndPrintBin(10);
    return 0;
}
