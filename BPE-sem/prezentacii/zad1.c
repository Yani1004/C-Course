#include <stdio.h>

int main(){
    char word[300];
    int nletters;
    printf("Enter: ");
    fgets(word,sizeof(word),stdin);
    nletters = strlen(word)-1;
    printf("%d",nletters);
    for(int i = 0;i<nletters;i++){
        printf("\n%d: ",i);
        for(int j = 0;j<i;j++){
            printf("%c",'*');
        }
    }

    return 0;
}
