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

int main() {
    char txt[100];
    printf("Text: ");
    gets(txt);
    int count = countLength(txt);
    printf("Length = %d", count);
    return 0;
}
