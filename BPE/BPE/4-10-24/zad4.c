#include <stdio.h>
#include <stdlib.h>

int *arrMemory(int columns) {
    int *arr = malloc(columns * sizeof(int));
    if (arr == NULL) {
        perror("error allocating memory");
        exit(1);
    }
    return arr;
}

void arrPrint(int *arr, int columns) {
    for (int i = 0; i < columns; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arrInit(int *arr, int columns) {
    for (int i = 0; i < columns; i++) {
        scanf("%d", &arr[i]);
    }
}

void printMenu() {
    printf("Menu:\n");
    printf("1.Init\n");
    printf("2.PrintAll\n");
    printf("3.Print excelent Nums \n");
    printf("4.Print failed count\n");
    printf("5.Add bonus\n");
    printf("6.Print Avg\n");
    printf("7.Add grade\n");
    printf("8.Del grade\n");
    printf("9.Exit\n");
    printf("Choose: ");
}

void addBonus(int *arr, int columns) {
    for (int i = 0; i < columns; i++) {
        if (arr[i] < 6) {
            arr[i]++;
        }
    }
}

void arrAdd(int **arr, int *columns) {
    (*columns)++;
    *arr = realloc(*arr, (*columns) * sizeof(int));
    if (*arr == NULL) {
        perror("error allocating memory");
        exit(1);
    }
    printf("Grade: ");
    scanf("%d", &(*arr)[(*columns) - 1]);
}

void arrDel(int **arr, int *columns, int index) {
    for (int i = index; i < (*columns) - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*columns)--;
    *arr = realloc(*arr, (*columns) * sizeof(int));
    if (*arr == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
}

int main() {
    int columns = 5;
    int *arr = arrMemory(columns);
    arrPrint(arr, columns);
    arrInit(arr, columns);
    addBonus(arr, columns);
    arrPrint(arr, columns);
    arrAdd(&arr, &columns);
    arrPrint(arr, columns);
    arrDel(&arr, &columns, 2);
    arrPrint(arr, columns);

    free(arr);
    return 0;
}
