#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME 56
#define ID 7

typedef struct Fitness {
    char full_name[NAME];
    char id[ID];
    double price;
    int code;
} Fitness;

void addMember() {
    FILE* fp;
    fp = fopen("membersText.txt", "a"); // Open file in append mode
    if (fp == NULL) {
        perror("Error opening file!");
        exit(EXIT_FAILURE);
    }

    Fitness member;
    printf("Enter the full name of the member: ");
    if (fgets(member.full_name, sizeof(member.full_name), stdin) == NULL) {
        perror("Error reading full name!");
        exit(EXIT_FAILURE);
    }
    member.full_name[strcspn(member.full_name, "\n")] = '\0';

    printf("Enter the id of the new member: ");
    if (scanf("%6s", member.id) != 1) { // Read up to 6 characters for ID
        perror("Error reading ID!");
        exit(EXIT_FAILURE);
    }

    printf("Enter the price: ");
    if (scanf("%lf", &member.price) != 1) { // Use %lf for double
        perror("Error reading price!");
        exit(EXIT_FAILURE);
    }

    printf("Enter the code: ");
    if (scanf("%d", &member.code) != 1) {
        perror("Error reading code!");
        exit(EXIT_FAILURE);
    }

    if (fprintf(fp, "%d;%s;%s;%.2f;%d\n", strlen(member.full_name), member.full_name, member.id, member.price, member.code) < 0) {
        perror("Error writing to file!");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

void printSpecificMember(const char id[ID]) {
    char full_name[NAME];
    char temp_id[ID];
    double price;
    int code;
    FILE* fp = fopen("members.bin", "rb");
    if (fp == NULL) {
        perror("Could not open the file");
        exit(EXIT_FAILURE);
    }
    while (fread(&full_name, sizeof(full_name), 1, fp) == 1) {
        if (fread(&temp_id, sizeof(temp_id), 1, fp) != 1 ||
            fread(&price, sizeof(price), 1, fp) != 1 ||
            fread(&code, sizeof(code), 1, fp) != 1) {
            perror("Error reading from file!");
            exit(EXIT_FAILURE);
        }
        if (strcmp(id, temp_id) == 0) {
            printf("Bin Name: %s\n", full_name);
            printf("Bin ID: %s\n", temp_id);
            printf("Bin M_Price: %.2f\n", price);
            printf("Bin Locker: %d\n", code);
        }
    }
    fclose(fp);
}

int main() {
    addMember();
    printSpecificMember("example_id");
    return 0;
}
