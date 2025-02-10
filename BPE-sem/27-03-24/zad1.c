#include <stdio.h>
#include <string.h>
int count(char txt[]){
        int count =0;
        for(int i = 0;i<strlen(txt);i++){
            if(txt[i]=='l'){
                count++;
            }
        }
        return count;

    }
int main(){
    char txt[15] ;//= "Hello World!";
    printf("Text: ");
    gets(txt);
    printf("%s\n",txt);
    char *txtPtr = txt;
    printf("%c\n",*(txtPtr+6));
    strcpy(txtPtr,txt);
    printf("Len: %d\n",strlen(txt));
    printf("%d\n",strcmp(txtPtr,txt));
    printf("l count: %d\n",count(txt));




    return 0;
}
