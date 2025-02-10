#include <stdio.h>
//strlen();
typedef struct Car{
    char** brand//[2][30];
}Car;


int main(){
    Car *myCarPtr;
    int inputSize;
    char temp[20];
    printf("How many car brands are you going to enter?");
    scanf("%d",&inputSize);
    getchar();
    myCarPtr = malloc(sizeof(Car));
    myCarPtr->brand = (char*)malloc(inputSize * sizeof(char*));
    int strSize;
    for(int i = 0; i < inputSize; i++){
        fgets(temp,20,stdin);
        temp[strlen(temp)-1]= '\0';
        strSize = strlen(temp)+1;
        myCarPtr->brand[i]= malloc(strSize);
        strcpy(myCarPtr->brand[i],temp);
        //printf("%s",myCarPtr->brand[i]);

    }

    for(int i = 0; i < 2; i++){
            for(int j = 0;i<)
        printf("%s\n",myCarPtr->sizeof(brand[i]));

    }

    //myCarPtr = malloc(sizeof(Car));
    //myCarPtr->brand = (char*)malloc(2 * sizeof(char*));
    /*for(int i = 0; i < inputSize; i++){
        fgets(temp,20,stdin);
        myCarPtr->brand[i]= malloc(20);

    }

    strcpy(myCarPtr->brand[0],"Ferrari");
    strcpy(myCarPtr->brand[1],"Audi");
    printf("%s\n",myCarPtr->brand[1]);
    /*
    Car myCar;
    myCar.brand=(char*)malloc(2*sizeof(char*));
    for(int i = 0; i < 2; i++){
        myCar.brand[i]= malloc(20);

    }
    strcpy(myCar.brand[0],"Ferrari");
    strcpy(myCar.brand[1],"Audi");
    printf("%s\n",myCar.brand[1]);
   /* printf("%d\n",sizeof(char*));
    printf("%d\n",sizeof(int));
    printf("%d",sizeof(int*));*/
    return 0;
}
