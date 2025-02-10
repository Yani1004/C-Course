#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LN 31
#define CHIP 8

struct Animal {
    char ownerName[LN];
    char chip[CHIP];
    float price;
};

void createPatient() {
    FILE *f;
    struct Animal animal;
    printf("Owner name: ");
    fgets(animal.ownerName, LN, stdin);
    animal.ownerName[strcspn(animal.ownerName, "\n")] = '\0';
    printf("Chip name: ");
    fgets(animal.chip, LN, stdin);
    printf("Price: ");
    scanf("%f", &animal.price);
    f = fopen("animalsText.txt", "w");
    if (f == NULL) {
        printf("The file is not opened. The program will now exit.");
        exit(0);
    } else {
        fprintf(f, "%s, %0.2f", animal.ownerName, animal.price);
    }
    fclose(f);
}

int main() {
    createPatient();
    return 0;
}
