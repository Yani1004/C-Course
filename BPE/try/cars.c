#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OWNER_NAME 36
#define REGISTRATION 9

typedef struct Cars {
    char owner_name[OWNER_NAME];
    char registration[REGISTRATION];
    double price;
    int priority;
} Cars;

void addCar(Cars car_arr[], int *num_cars) {
    FILE *fp;
    fp = fopen("autoText.txt", "at");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    Cars temp_car;
    printf("Enter car owner name: ");
    fgets(temp_car.owner_name, OWNER_NAME, stdin);
    temp_car.owner_name[strcspn(temp_car.owner_name, "\n")] = '\0';

    printf("Enter registration code: ");
    scanf("%8s", temp_car.registration);

    printf("Enter price: ");
    scanf("%lf", &temp_car.price);

    printf("Enter priority: ");
    scanf("%d", &temp_car.priority);

    fprintf(fp, "%s;%s;%.2lf;%d\n", temp_car.owner_name, temp_car.registration, temp_car.price, temp_car.priority);
    fclose(fp);

    car_arr[*num_cars] = temp_car;
    (*num_cars)++;
}

void printAboveAverage(Cars cars_arr[], int num_cars) {
    double total_price = 0.0;
    for (int i = 0; i < num_cars; i++) {
        total_price += cars_arr[i].price;
    }
    double average_price = total_price / num_cars;

    printf("Average Price: %.2lf\n", average_price);

    for (int i = 0; i < num_cars; i++) {
        if (cars_arr[i].price > average_price) {
            printf("%s - %.2lf\n", cars_arr[i].registration, cars_arr[i].price);
        }
    }
}

void readFromBin(char registration_search[]) {
    FILE *fp;
    char owner_name[OWNER_NAME];
    char registration[REGISTRATION];
    int sizeName, priority;
    double price;

    fp = fopen("auto.bin", "rb");
    if (fp == NULL) {
        perror("Reading error!");
        exit(1);
    }

    while (fread(&sizeName, sizeof(sizeName), 1, fp) == 1) {
        if (fread(owner_name, sizeof(char), sizeName, fp) != sizeName) {
            perror("Reading error!");
            exit(1);
        }
        owner_name[sizeName] = '\0';

        if (fread(registration, sizeof(char), REGISTRATION, fp) != REGISTRATION) {
            perror("Reading error!");
            exit(1);
        }

        if (fread(&price, sizeof(price), 1, fp) != 1) {
            perror("Reading error!");
            exit(1);
        }

        if (fread(&priority, sizeof(priority), 1, fp) != 1) {
            perror("Reading error!");
            exit(1);
        }

        if (strcmp(registration, registration_search) == 0) {
            printf("\nBin Name: %s", owner_name);
            printf("\nBin L_Plate: %s", registration);
            printf("\nBin Price: %.2f", price);
            printf("\nBin Priority: %d", priority);
            break;
        }
    }
    fclose(fp);
}

int main() {
    Cars car_arr[100];
    int num_cars = 0;

    addCar(car_arr, &num_cars);
    printAboveAverage(car_arr, num_cars);
    readFromBin("ABC123");

    return 0;
}
