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
void timesLetters(char txt[]){
    int length = countLength(txt);
    for(int i = 0;i<length;i++){
        int count = 0;
        for(int j = 0;j<length;j++){
           if(txt[i]==txt[j]){
                count++;
           }
        }
        printf("%c = %d\n",txt[i],count);
    }

}
int main() {
    char txt[100];
    printf("Text: ");
    gets(txt);
    timesLetters(txt);
    return 0;
}
