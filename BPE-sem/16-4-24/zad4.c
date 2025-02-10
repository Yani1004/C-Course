#include <stdio.h>
#include <stdlib.h>

int *arrMemory(int size) {
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    return arr;
}

void arrInit(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Number %d = ", i);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int size = 10;
    int *arr = arrMemory(size);
    arrInit(arr, size);
    int num, index;
    while (1) {
        printf("Enter number and index (or 0 to exit): ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        scanf("%d", &index);

        if (index < 0 || index >= size) {
            printf("Invalid index!\n");
            continue;
        }

        if (size == index) {
            size *= 2;
            arr = realloc(arr, size * sizeof(int));
            if (arr == NULL) {
                perror("Error reallocating memory");
                exit(1);
            }
        }

        for (int i = size - 1; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = num;
        printf("Updated array: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}
