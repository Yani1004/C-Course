#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME 31
#define ADDRESS 51
#define PHONE 11

typedef struct Contact {
    char name[NAME];
    char address[ADDRESS];
    char phone[PHONE];
    int age;
} Contact;

void updateContact(Contact contacts[], int *n, Contact temp, int index) {
    if (index >= *n) {
        perror("Index is out of range");
        return;
    }
    strcpy(contacts[index].name, temp.name);
    strcpy(contacts[index].address, temp.address);
    strcpy(contacts[index].phone, temp.phone);
    contacts[index].age = temp.age;
}

Contact* deleteContact(Contact contacts[], int *n, char name[NAME], char phone[PHONE]) {
    int foundIndex = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(contacts[i].name, name) == 0 && strcmp(contacts[i].phone, phone) == 0) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        perror("Contact not found!");
        return NULL;
    }

    for (int i = foundIndex; i < *n - 1; ++i) {
        strcpy(contacts[i].name, contacts[i + 1].name);
        strcpy(contacts[i].address, contacts[i + 1].address);
        strcpy(contacts[i].phone, contacts[i + 1].phone);
        contacts[i].age = contacts[i + 1].age;
    }

    --*n;
    contacts = (Contact*)realloc(contacts, (*n) * sizeof(Contact));
    if (contacts == NULL) {
        perror("Memory allocation failed!");
        exit(1);
    }
    return contacts;
}

int writeTxtFile(Contact contacts[], int n, int min, int max) {
    FILE *fp;
    fp = fopen("envelopes.txt", "w");
    if (fp == NULL) {
        perror("Could not open the file!");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        if (min <= contacts[i].age && contacts[i].age <= max) {
            fprintf(fp, "%s\n%s\n", contacts[i].name, contacts[i].phone);
        }
    }
    fclose(fp);
    return 0;
}

void createBinFile() {
    FILE *fp;
    int n;
    printf("How many contacts will you enter: ");
    scanf("%d", &n);
    fp = fopen("contacts.bin", "wb");
    if (fp == NULL) {
        perror("Error");
        exit(1);
    }
    fwrite(&n, sizeof(n), 1, fp);
    getchar();

    for (int i = 0; i < n; i++) {
        Contact temp;
        printf("Enter contact's name: ");
        fgets(temp.name, sizeof(temp.name), stdin);
        temp.name[strcspn(temp.name, "\n")] = '\0';

        printf("Enter contact's address: ");
        fgets(temp.address, sizeof(temp.address), stdin);
        temp.address[strcspn(temp.address, "\n")] = '\0';

        printf("Enter contact's phone number: ");
        fgets(temp.phone, sizeof(temp.phone), stdin);
        temp.phone[strcspn(temp.phone, "\n")] = '\0';

        printf("Enter contact's age: ");
        scanf("%d", &temp.age);
        getchar();
        fwrite(&temp, sizeof(Contact), 1, fp);
    }
    fclose(fp);
}

int main() {
    int n;
    Contact *contacts = NULL;
    createBinFile();
    FILE *fp;
    fp = fopen("contacts.bin", "rb");
    if (fp == NULL) {
        perror("Could not read from file!");
        exit(1);
    }
    if (fread(&n, sizeof(int), 1, fp) != 1) {
        perror("Reading error!");
        fclose(fp);
        exit(1);
    }
    contacts = (Contact *)malloc(n * sizeof(Contact));
    if (contacts == NULL) {
        perror("Could not allocate memory!");
        fclose(fp);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        if (fread(contacts[i].name, sizeof(char), NAME, fp) != NAME ||
            fread(contacts[i].address, sizeof(char), ADDRESS, fp) != ADDRESS ||
            fread(contacts[i].phone, sizeof(char), PHONE, fp) != PHONE ||
            fread(&contacts[i].age, sizeof(int), 1, fp) != 1) {
            perror("Reading error!");
            fclose(fp);
            free(contacts);
            exit(1);
        }
    }
    Contact temp;
    strcpy(temp.name, "John Doe");
    strcpy(temp.address, "123 Main St");
    strcpy(temp.phone, "1234567890");
    temp.age = 30;
    updateContact(contacts, &n, temp, 0);


    deleteContact(contacts, &n, "John Doe", "1234567890");


    int written = writeTxtFile(contacts, n, 30, 40);
    printf("%d", written);
    fclose(fp);
    free(contacts);
    return 0;
}
