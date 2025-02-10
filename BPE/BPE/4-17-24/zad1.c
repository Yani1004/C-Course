#include <stdio.h>

typedef struct Student{
    char name[50];
    double grade;
}Student;

int main(){
    char name[50];
    double grade;
    Student s1,s2;
    printf("Name: ");
    scanf("%s",name);
    printf("Grade: ");
    scanf("%lf",&grade);
    strcpy(s1.name,name);
    s1.grade = grade;
    printf("Name: ");
    scanf("%s",name);
    printf("Grade: ");
    scanf("%lf",&grade);
    strcpy(s2.name,name);
    s2.grade = grade;
    printf("%s achieved %.2f\n",s1.name,s1.grade);
    printf("%s achieved %.2f\n",s2.name,s2.grade);
    printf("Wrong name!");

    printf("Name: ");
    scanf("%s",name);
    printf("Grade: ");
    scanf("%lf",&grade);
    strcpy(s1.name,name);
    s1.grade = grade;

    printf("%s achieved %.2f\n",s1.name,s1.grade);
    printf("%s achieved %.2f",s2.name,s2.grade);
    return 0;
}
