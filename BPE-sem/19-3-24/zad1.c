#include <stdio.h>

int main(){
    char symbol;
    printf("Type in the symbol: ");
    scanf("%c",&symbol);

    for(int i = 0;i<5;i++){
        if(i==0|| i == 4){
            for(int j = 0;j<10;j++){
                printf("%c",symbol);
            }
            printf("\n");
        }else{
            printf("%c",symbol);
            for(int j = 0;j<8;j++){
                printf(" ",symbol);
            }
            printf("%c\n",symbol);

        }
    }

    return 0;
}



