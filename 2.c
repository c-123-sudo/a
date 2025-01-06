// Write a C program to find the fast transpose of a sparse matrix. 
#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

void transpose(Term a[], Term b[]);

int main() {
    Term a[MAX], b[MAX];
    int n;

    printf("Enter the number of rows, columns, and non-zero elements of the sparse matrix:\n");
    scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].value);

    n = a[0].value;

    printf("Enter the triplets (row, column, value) of the sparse matrix:\n");
    for (int i = 1; i <= n; i++) {
        printf("Element %d: ", i);
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    transpose(a, b);

    printf("\nFast Transposed Sparse Matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= b[0].value; i++) {
        printf("%d\t%d\t%d\n", b[i].row, b[i].col, b[i].value);
    }

    return 0;
}

void transpose(Term a[], Term b[]) {
    int n = a[0].value; // Total number of non-zero elements
    b[0].row = a[0].col; // Rows in b = Columns in a
    b[0].col = a[0].row; // Columns in b = Rows in a
    b[0].value = n;

    if (n > 0) {
        int currentb = 1; // Tracks position in b

        for (int i = 0; i < a[0].col; i++) { // Iterate over each column of the original matrix
            for (int j = 1; j <= n; j++) {  // Find elements in the current column
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}
// Enter the number of rows, columns, and non-zero elements of the sparse matrix:
// 3 3 4
// Enter the triplets (row, column, value) of the sparse matrix:
// Element 1: 0 0 5
// Element 2: 0 2 8
// Element 3: 1 1 3
// Element 4: 2 0 6
// Fast Transposed Sparse Matrix:
// Row    Col    Value
// 3      3      4
// 0      0      5
// 0      2      6
// 1      1      3
// 2      0      8
