#include <stdio.h>
#include <stdbool.h>

int main(){
    char a = 'C';            //single character %c
    char b[]= "Yanitsa";  //array of characters %s

    float c = 3.141592653589793;       //4 bytes(32 bits precision) %f 6-7 digits
    double d = 3.141592653589793; // 8 bytes (64 bits of precision) %lf 15-16 digits
    bool e = true; //need to include <stdbool.h> to use boolean
    // 1 byte(true=1 or false=0) %d

    char f = 119; //1 byte (-128 to +127)%d or %c(for the ascii table)
    unsigned char g = 255; // 1 byte (0 to +255) %d or %c (unsigned = only 0 and positive numbers)
    // if we use a number bigger than 255 it automatically changes it to 0

    short int h = 32767; //2 bytes (-32 768 to 32 767) %d
    //can by used just as short h = 366;
    unsigned short int i = 65535;  // 2 bites (0 to  65535) %d

    int j = 2147483647; //4 bytes (-2 147 483 648 to 2 147 483 647) %d
    unsigned int k = 4294967295L; // 4 bytes (0 to 4 294 967 295)%u

    long long int l = 854411112363665478; //8 bytes %lld
    unsigned long long int m = 465198645388456U; // 8 bytes %llu

    //printf("%c\n",a);
    //printf("%s\n",b);
    //printf("%f\n",c);
    //printf("%lf\n",d);
    //printf("%d\n",e);
    //printf("%d\n",f);
    //printf("%c\n",f);
    //printf("%d\n",g);
    //printf("%d\n",h);
    //printf("%u\n",i);
    //printf("%d\n",j);
    //printf("%u\n",k);
    //printf("%lld\n",l);
    //printf("%llu\n",m);

    // format specifier % = defines and formats type of data to be displayed

    //%d - integer
    //%f - floating point number
    //%c - character
    //%s - string
    //%u - Unsigned integer

    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 1100.99;

    //printf("Item 1 : $%6.2f\n",item1);
    //printf("Item 2 : $%6.2f\n",item2);
    //printf("Item 3 : $%6.2f",item3);

    // constants = fixed value that cannot be altered by the program during its execution

    const float PI = 3.14159;
    printf("%f",PI);

    return 0;
}
