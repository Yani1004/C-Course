#include <stdio.h>

int countLength(char txt[]) {
    int length = 0;
    int i = 0;
    while(txt[i] != '\0') {
        i++;
        length++;
    }
    return length;
}
int checkLetter(char txt[],char letter){
    int len = countLength(txt);
    int found = 0;
    for(int i = 0;i<=len;i++){
        if(txt[i]==letter){
            return i;
        }
    }
    found = -1;
    return found;
}

int main() {
    char txt[100];
    printf("Text: ");
    gets(txt);
    char letter;
    printf("letter to search: ");
    scanf("%c",&letter);
    int check = checkLetter(txt,letter);
    printf("%d",check);
    return 0;
}
