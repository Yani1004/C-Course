#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
int main(){
    float price_vegs,price_fruits,kg_veggies,kg_fruis;
    printf("Price Veggies: ");
    scanf("%f",price_vegs);
    printf("Price Fruits: ");
    scanf("%f",price_fruits);
    printf("Kg Veggies: ");
    scanf("%f",kg_veggies);
    printf("Kg Fruits: ");
    scanf("%f",kg_fruis);

    float total = price_vegs*kg_veggies + price_fruits*kg_fruis;
    total/=1.95;
    printf("Total is %.2f.", total);

    return 0;
}

*/

//13 zadacha
int main(){
    float w,h;
    printf("Width = ");
    scanf("%f",&w);
    printf("Height = ");
    scanf("%f",&h);
    int total, desks_w,desks_h;
    desks_w = (int)(h/0.7)-1;
    desks_h = (int)w/1.2;
    total = (desks_w*desks_h)-3;

    printf("%d",total);

    return 0;
}

// 11 zadacha
int main(){
    float x1;
    printf("X1= ");
    scanf("%f",&x1);
    float y1;
    printf("Y1= ");
    scanf("%f",&y1);
    float x2;
    printf("X2= ");
    scanf("%f",&x2);
    float y2;
    printf("Y2= ");
    scanf("%f",&y2);
    float side1,side2,area;
    side1 = abs(x1)-abs(x2);
    side2 = abs(y1)-abs(y2);
    area = side1*side2;
    printf("%f",area);

    return 0;
}

//9 zadacha
int main(){
    float a;
    printf("A: ");
    scanf("%f",&a);
    float b;
    printf("B: ");
    scanf("%f",&b);
    float h;
    printf("H: ");
    scanf("%f",&h);
    float area =(a+b)/2*h;
    printf("Area = %f",area);

    return 0;
}
//8 zadacha
int main(){
    float levs;
    printf("Leva: ");
    scanf("%f",&levs);

    float dollar = levs *0.56;
    float euro = levs * 0.51;
    float pound = levs * 0.44;
    printf("%f Leva = %f Dollar = %f Euro = %f Pound", levs,dollar,euro,pound);

    return 0;
}

int main(){
    float cels;
    printf("Celsius: ");
    scanf("%f",&cels);

    float fahr = (cels*9/5)+32;

    printf("\n%.2f Celsius = %.2f Fahrenheit", cels,fahr);

    return 0;
}

int main(){
    float inch;
    printf("Inches: ");
    scanf("%f",&inch);


    float mm = inch*25.4;
    float cm = inch*2.54;
    float dm = inch*0.254;
    float m = inch*0.0254;
    printf("%.3f Inches = %.3f Millimeter = %.3f Centimeter = %.3f Decimeter = %.3f meter ",inch,mm,cm,dm,m);

}


