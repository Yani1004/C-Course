#include <stdio.h>

int main(){
    // arithmetic operators

    // + addition
    // - subtraction
    // * multiplication
    // / division
    // % modulus
    // ++ increment
    // -- decrement

    int x = 5;
    int y = 2;

    //float z = x/(float) y; // is 2 cuz we store the result in an integer and
    // the decimal portion will be truncated
    //float z1 = x/y;
    //printf("%f",z);

    int z = x%y;
    x++;
    x++;
    y--;
    printf("%d\n",x);
    printf("%d\n",y);
    printf("%d",z);

    // augmented assignment operators - used to replace where and operator
    //                                  takes a variable as one of its arguments and then
    //                                  assigns the result back to the same variable
    //                                  x = x + 1;
    //                                  x += 1;
    int num = 10;
    //num +=5;

    //num -=4;

    //num *=2;

    //num +=5;
    num %=2;
    //printf("%d\n",num);

return 0;
}
