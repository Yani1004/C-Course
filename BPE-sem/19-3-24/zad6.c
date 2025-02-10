#include <stdio.h>

int main(){
    int points;
    float bonus,total;
    printf("Type in the points: ");
    scanf("%d",&points);
    if(points<=100){
        bonus = 5;
    }else if(points >100 && points <1000){
        bonus = 0.2*points;
    }else{
        bonus = 0.1*points;
    }

    if(points % 2 == 0){
        bonus +=1;
    }else if(points % 5 == 0){
        bonus +=2;
    }
    printf("%.f\n",bonus);
    total = points + bonus;
    printf("%.f",total);
    return 0;
}
