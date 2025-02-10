#include <stdio.h>
int countLen(char txt[]){
    int length = 0;
    int j = 0;
    while(txt[j] != '\0') {
        j++;
        length++;
    }
    return length;
}
int compare(char txt1[],char txt2[]){
    int same=0;
    int count1 = countLen(txt1);
    int count2 = countLen(txt2);
    //printf("%d,%d",count1,count2);
    if(count1!=count2){
        return same;
    }else{
        for(int i = 0;i<count1;i++){
            if(txt1[i]!=txt2[i]){
                same = 0;
                return same;
            }else{
                same = 1;
            }
        }
    }
    return same;


}
int main(){
    char txt1[1000];
    printf("Text 1: ");
    gets(txt1);
    char txt2[1000];
    printf("Text 2: ");
    gets(txt2);
    int comparison = compare(txt1,txt2);
    printf("%d",comparison);
    return 0;
}
