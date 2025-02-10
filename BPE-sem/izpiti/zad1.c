#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH_TYPE 7
#define MAX_LENGTH_DATA 11
#define MAX_LENGTH_NAME 31
typedef struct Transaction{
    char type[MAX_LENGTH_TYPE];
    char date[MAX_LENGTH_DATA];
    char name[MAX_LENGTH_NAME];
    double amount;
}Transaction;
//zadacha2
void findBiggestCredit(Transaction transactions[],int n){
    if(n<=0){
        perror("Invalid!");
        return 1;
    }
    double max = -1;
    int index=-1;
    for(int i = 0;i<n;i++){
        if(strcpy(transactions[i].type,"credit")==0){
            if(transactions[i].amount>max){
                max = transactions[i].amount;
                index = i;
            }
        }
    }
    if(index==-1){
        printf("No credit transactions");
    }else{
        printf("%s\n%s\n%s\n%.2lf",transactions[index].type,transactions[index].date,transactions[index].name,transactions[index].amount);
    }
}
//zadacha3
Transaction *updateTransaction(Transaction transactions[],int *n, int index){
    if(index<0||index>=n){
        perror("Invalid");
        return NULL;
    }
    *n++;
    transactions = realloc(transactions,*n*sizeof(Transaction));
    if(transactions == NULL){
        perror("Could not allocate memory!");
        return NULL;
    }
    if(strcmp(transactions[index].type,"debit")==0){
        strcpy(transactions[*n-1].type,"credit");
    }
    strcpy(transactions[*n-1].date,transactions[index].date);
    strcpy(transactions[*n-1].name,transactions[index].name);
    strcat(transactions[*n-1].name,"otmqna");
    transactions[*n-1].amount = transactions[index].amount;
    return transactions;
}
//zadacha4
int writeToBin(Transaction transactions[],int n){
    FILE*fp;
    fp = fopen("balance.bin","wb");
    if(fp==NULL){
        perror("Error opening file!");
        fclose(fp);
        return 1;
    }
    if(fwrite(&n,1,sizeof(int),fp)!=1){
        perror("Cannot write to file!");
        fclose(fp);
        return 1;
    }
    for(int i = 0;i<n;i++){
      if(fwrite(transactions[i].type,MAX_LENGTH_TYPE,sizeof(char),fp)!=MAX_LENGTH_TYPE||
         fwrite(transactions[i].date,MAX_LENGTH_DATA,sizeof(char),fp)!=MAX_LENGTH_DATA||
         fwrite(transactions[i].name,MAX_LENGTH_NAME,sizeof(char),fp)!=MAX_LENGTH_NAME||
         fwrite(&transactions[i].amount,1,sizeof(double),fp)!=1){
            perror("Cannot write to file!");
            fclose(fp);
            return 1;
         }
    }
    fclose(fp);
    return 0;
}

//zadacha1
int main(){
    Transaction *transactions=NULL;
    int n = 0;
    FILE*fp;

    fp = fopen("statements.txt","r");
    if(fp == NULL){
        perror("Error: ");
        return 1;
    }

    if(fscanf(fp,"%d",&n)!=1){
        perror("Could not read!");
        fclose(fp);
        return 1;
    }
    transactions = (Transaction*)malloc(n*sizeof(Transaction));
    for(int i=0;i<n;i++){
        if(fscanf(fp,"%s %s %s %lf",transactions[i].type,transactions[i].date,transactions[i].name,transactions[i].amount)!=4){
            perror("Could not read!");
            fclose(fp);
            free(transactions);
            return 1;
        }
    }
    fclose(fp);
    free(transactions);
    return 0;
}


