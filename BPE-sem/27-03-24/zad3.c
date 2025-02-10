#include <stdio.h>
int countWords(char txt[]){
    int length = 0;
    int j = 0;
    while(txt[j] != '\0') {
        j++;
        length++;
    }
    int words = 0;
    for(int i = 0;i<=length;i++){
        if(txt[i]==' '){
            words++;
        }
    }
    return words+1;

}
int main(){
    char txt[1000];
    printf("Text: ");
    gets(txt);
    int words = countWords(txt);
    printf("Words = %d", words);
    return 0;
}
