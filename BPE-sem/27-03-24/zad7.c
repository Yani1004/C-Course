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

void concatenateStrings(char txt1[],char txt2[], char result[]) {
    int i = 0, j = 0;
    while (txt1[i] != '\0') {
        result[j] = txt1[i];
        i++;
        j++;
    }

    i = 0;
    while (txt2[i] != '\0') {
        result[j] = txt2[i];
        i++;
        j++;
    }
    result[j] = '\0';
}

int main() {
    char txt1[1000];
    printf("Text: ");
    gets(txt1);
    char txt2[1000];
    printf("Text 2: ");
    gets(txt2);
    char result[2000];
    concatenateStrings(txt1,txt2,result);
    printf("%s",result);
    return 0;
}
