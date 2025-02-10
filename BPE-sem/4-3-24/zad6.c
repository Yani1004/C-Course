#include <stdio.h>

int main() {
    int n;
    printf("N: ");
    scanf("%d", &n);

    int matrix[n][n];


    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }


    printf("Matrix entered:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[0][i];
    }
    int magic = 1;
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) {
            magic = 0;
            break;
        }
    }

    if (magic==1) {
        for (int i = 0; i < n; i++) {
            int colSum = 0;
            for (int j = 0; j < n; j++) {
                colSum += matrix[j][i];
            }
            if (colSum != sum) {
                magic = 0;
                break;
            }
        }
    }

    if (magic==1) {
        printf("Magic Square!\n");
    } else {
        printf("Not a Magic Square!\n");
    }

    return 0;
}
