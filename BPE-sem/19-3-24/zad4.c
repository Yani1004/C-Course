#include <stdio.h>

int main(){
    int hour,minutes;
    printf("Hour: ");
    scanf("%d",&hour);
    printf("Minutes: ");
    scanf("%d",&minutes);
    int minutesAfterFifteen = minutes + hour * 60+15;
    int hoursAfter15 = minutesAfterFifteen/60;
    int mins = minutesAfterFifteen%60;
    if(mins <10){
        printf("%d :0%d",hoursAfter15,mins);
    }else{
        printf("%d :%d",hoursAfter15,mins);
    }



    return 0;
}
