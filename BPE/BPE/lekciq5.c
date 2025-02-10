#include <stdio.h>
#include <stdlib.h> // for exit
#include <string.h> // for strcpy

struct Car {
    char brand[50];
    int horsePower;
    double price;
    char model[50];
};

int main() {
    struct Car cars[2];
    strcpy(cars[0].brand, "Audi");
    strcpy(cars[0].model, "RS7");
    cars[0].price = 49999.5;
    cars[0].horsePower = 500;
    strcpy(cars[1].brand, "BMW");
    strcpy(cars[1].model, "E60");
    cars[1].price = 25660.5;
    cars[1].horsePower = 250;

    FILE *fp;
    fp = fopen("newFile.new", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < 2; i++) {
        fwrite(&(cars[i]), sizeof(struct Car), 1, fp);
    }

    fclose(fp);

    return 0;
}
