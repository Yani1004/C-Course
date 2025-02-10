#include <stdio.h>

struct Student{
    char name[50];
    double grade;
};

void printMenu() {
    printf("\nMenu:\n");
    printf("1- Init all students\n");
    printf("2- Print all students\n");
    printf("3- Print names of excellent students\n");
    printf("4- Give one bonus\n");
    printf("0- Exit\n");
}
void initStudents(struct Student std[]){
    char name[50];
    double grade;
    for(int i = 0;i<5;i++){
        printf("Name: ");
        scanf("%s",name);
        printf("Grade: ");
        scanf("%lf",&grade);
        while(grade<2||grade >6){
            printf("Invalid!");
            printf("Grade: ");
            scanf("%lf",&grade);
        }
        strcpy(std[i].name,name);
        std[i].grade = grade;
    }
}
void printAll(struct Student std[]){
    for(int i = 0;i< 5;i++){
        printf("%s has achieved %.2f\n",std[i].name,std[i].grade);
    }
}
void namesExcellent(struct Student std[]){
    for(int i = 0;i< 5;i++){
       if(std[i].grade>=5.5){
        printf("%s ",std[i].name);
       }
    }
}
void addBonus(struct Student std[]){
     for(int i = 0;i< 5;i++){
       if(std[i].grade>5){
            std[i].grade = 6;
       }else{
            std[i].grade+=1;
       }
    }
}
int main() {
    int n;
    struct Student std[5];

    do {
        printMenu();
        scanf("%d", &n);
        switch (n) {
            case 1:
                initStudents(std);
                break;
            case 2:
                printAll(std);
                break;
            case 3:
                namesExcellent(std);
                break;
            case 4:
                addBonus(std);
                break;
        }
    } while (n != 0);

    return 0;
}
