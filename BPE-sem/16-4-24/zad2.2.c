#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *arrMemory(int columns) {
    int *arr = malloc(columns * sizeof(int));
    if (arr == NULL) {
        perror("error allocating memory");
        exit(1);
    }
    return arr;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void arrInit(int *arr, int columns) {
    for (int i = 0; i < columns; i++) {
        printf("Number %d = ", i);
        scanf("%d", &arr[i]);
    }
}

int arrDel(int **arr, int *columns, int **arr2) {
    int count = *columns;
    int shiftIndex = 0;
    for (int i = 0; i < count; i++) {
        if (isPrime((*arr)[i])) {
            (*arr2)[shiftIndex++] = (*arr)[i];
            for (int j = i; j < count - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }
            (*columns)--;
            i--;
            count--;
        }
    }
    *arr = realloc(*arr, (*columns) * sizeof(int));
    if (*arr == NULL && *columns > 0) {
        perror("Error reallocating memory");
        exit(1);
    }
    return shiftIndex;
}

void arrPrint(int *arr, int columns) {
    for (int i = 0; i < columns; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int columns;
    printf("Type in columns: ");
    scanf("%d", &columns);
    int *arr = arrMemory(columns);
    int *arr2 = arrMemory(columns);
    arrInit(arr, columns);

    int n = arrDel(&arr, &columns, &arr2);
    printf("Array after removing primes: ");
    arrPrint(arr, columns);
    printf("Primes stored in arr2: ");
    arrPrint(arr2, n);
    free(arr);
    free(arr2);
    return 0;
}
