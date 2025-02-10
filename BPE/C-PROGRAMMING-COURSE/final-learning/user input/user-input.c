#include <stdio.h>
#include <string.h>

int main(){

    char name[25];//bytes
    int age;

    printf("What is your name?  ");
    //scanf("%s",&name);
    fgets(name, 25,stdin);
    name[strlen(name)-1] = '\0';
    //fgets includes a new line character as default
    printf("How old are you?");
    scanf("%d",&age);
    // if you type something with a whitespace it cuts!
    // ex: Yani Mavreva => Yani
    // we read up to a whitespace with scanf


    printf("\nHello, %s,how are you!",name);
    printf("\nYou are %d years old!",age);


    return 0;
}
