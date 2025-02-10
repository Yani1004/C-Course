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

void arrInit(int *arr, int columns) {
    for (int i = 0; i < columns; i++) {
        printf("Number %d = ", i);
        scanf("%d", &arr[i]);
    }
}

void add(int **arr, int *columns) {
    (*columns)++;
    *arr = realloc(*arr, (*columns) * sizeof(int));
    if (*arr == NULL) {
        perror("Error!");
        exit(1);
    }
    printf("Type X: ");
    scanf("%d", &(*arr)[*columns - 1]);
}

void arrPrint(int *arr, int columns) {
    for (int i = 0; i < columns; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arrDel(int **arr, int *columns) {
    int x;
    printf("Element you want to delete: ");
    scanf("%d", &x);
    int count = *columns;
    int shiftIndex = 0;
    for (int i = 0; i < count; i++) {
        if ((*arr)[i] == x) {
            for (int j = i; j < count - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*columns)--;
            i--;
        }
    }

    *arr = realloc(*arr, (*columns) * sizeof(int));
    if (*arr == NULL) {
        perror("Error!");
        exit(1);
    }
}

int smallest(int *arr, int columns) {
    int smallest = arr[0];
    for (int i = 0; i < columns; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    printf("The smallest number is : %d\n", smallest);
    return smallest;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1- Add(x)\n");
    printf("2- Delete(x)\n");
    printf("3- Smallest(X)\n");
    printf("0- Exit\n");
}

int main() {
    int columns, n;
    printf("Type in columns: ");
    scanf("%d", &columns);
    int *arr = arrMemory(columns);
    arrInit(arr, columns);
    do {
        printMenu();
        scanf("%d", &n);
        switch (n) {
            case 1:
                add(&arr, &columns);
                arrPrint(arr, columns);
                break;
            case 2:
                arrDel(&arr, &columns);
                arrPrint(arr, columns);
                break;
            case 3:
                smallest(arr, columns);
                break;
        }
    } while (n != 0);
    free(arr);
    return 0;
}
