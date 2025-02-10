#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CODE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char code[MAX_CODE_LENGTH];
    float price;
} AnimalInfo;

void createBinaryFile() {
    FILE *filePtr;
    AnimalInfo animal;

    // Open the binary file for writing
    filePtr = fopen("animalsBin.bin", "wb");

    if (filePtr == NULL) {
        perror("Error opening file");
        return;
    }

    // Prompt the user to input information for each animal
    int numAnimals;
    printf("Enter the number of animals: ");
    scanf("%d", &numAnimals);

    for (int i = 0; i < numAnimals; i++) {
        printf("Animal %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", animal.name);
        printf("Code: ");
        scanf("%s", animal.code);
        printf("Price: ");
        scanf("%f", &animal.price);

        // Write the information to the binary file
        fwrite(&animal, sizeof(AnimalInfo), 1, filePtr);
    }

    // Close the file
    fclose(filePtr);

    printf("Binary file created successfully.\n");
}

int main() {
    createBinaryFile();
    return 0;
}
