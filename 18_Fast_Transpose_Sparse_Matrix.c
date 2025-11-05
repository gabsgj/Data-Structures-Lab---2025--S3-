#include <stdio.h>

void fastTranspose(int original[][3], int transposed[][3]){

    int row = original[0][0];
    int col = original[0][1];
    int numTerms = original[0][2];

    if (numTerms == 0) {
        transposed[0][0] = col;
        transposed[0][1] = row;
        transposed[0][2] = 0;
        return;
    }

    int count[col];
    for (int i = 0; i < col; i++)
        count[i] = 0;
    for (int i = 1; i <= numTerms; i++)
        count[original[i][1]]++;

    for (int i = 1; i < col; i++)
        count[i] += count[i - 1];

    transposed[0][0] = col;
    transposed[0][1] = row;
    transposed[0][2] = numTerms;

    for (int i = numTerms; i >= 1; i--) {
        int colIndex = original[i][1];
        int pos = --count[colIndex];
        transposed[pos + 1][0] = original[i][1];
        transposed[pos + 1][1] = original[i][0];
        transposed[pos + 1][2] = original[i][2];
    }
}



int main() {
    int rows, cols, numTerms;

    printf("Enter number of rows in the sparse matrix: ");
    scanf("%d", &rows);

    printf("Enter number of columns in the sparse matrix: ");
    scanf("%d", &cols);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &numTerms);

    int original[numTerms + 1][3];
    int transposed[numTerms + 1][3];

    original[0][0] = rows;
    original[0][1] = cols;
    original[0][2] = numTerms;

    printf("\nEnter the non-zero elements in (row col value) format:\n");
    for (int i = 1; i <= numTerms; i++) {
        printf("Element %d -> ", i);
        scanf("%d %d %d", &original[i][0], &original[i][1], &original[i][2]);
    }

    printf("\nOriginal Sparse Matrix (3-tuple form):\n");
    for (int i = 0; i <= numTerms; i++) {
        printf("%d %d %d\n", original[i][0], original[i][1], original[i][2]);
    }

    fastTranspose(original, transposed);

    printf("\nTransposed Sparse Matrix (3-tuple form):\n");
    for (int i = 0; i <= transposed[0][2]; i++) {
        printf("%d %d %d\n", transposed[i][0], transposed[i][1], transposed[i][2]);
    }
}