#include <stdio.h>

int main(){
    /*variables = Allocated space in memory to store value
                  We refer to variable's name to access stored value
                  That variable now behaves as if it was the value it contains
                  BUT we need to declare what type of data we are storying
                  */

    int x; //declaration
    x=123 ;//initialization
    int y = 321; //declaration + initialization

    int age = 21; //integer
    float height = 1.71; // floating point number
    char symbol = 'V'; //single character
    char name[]= "Yanitsa";//array of characters
    printf("Hello %s!\t",name);
    printf("You are %d years old",age);
    printf("\tYour height is %4.2f\n",height);
    printf("%c is your bf initial",symbol);


    // format specifiers for different data types
    //%d - integer
    //%f - floating point number
    //%c - character
    //%s - string
    /*%u - Unsigned integer
        %ld - Long integer
        %lu - Unsigned long integer
        %lld - Long long integer
        %llu - Unsigned long long integer
        %x - Lowercase hexadecimal integer
        %X - Uppercase hexadecimal integer
        %o - Octal integer
        %e - Scientific notation (lowercase)
        %E - Scientific notation (uppercase)
        %g - Shortest representation of %f and %e
        %G - Shortest representation of %f and %E
        %% - Print a single percent sign '%'
*/

    int num = 123456;
    printf("\nDecimal : %d \nhexadecimal : %x \nOctal : %o\n",num,num,num);
    printf("%-10s%10s%10s\n", "Name", "Age", "Height");
    return 0;
}
