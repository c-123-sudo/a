#include <stdio.h>

// Structure to represent a term in the sparse matrix
typedef struct {
    int r, c, v;
} term;

// Function to perform fast transpose of a sparse matrix
void transpose(term a[], term t[]) {
    int rt[10], sp[10];
    int i, j;
    int numcols = a[0].c;  // Number of columns in the original matrix
    int numterms = a[0].v; // Number of non-zero elements in the matrix

    // Set the metadata for the transposed matrix
    t[0].r = numcols;
    t[0].c = a[0].r;
    t[0].v = numterms;

    // If there are non-zero elements, proceed with the transpose
    if (numterms > 0) {
        // Step 1: Initialize row terms (rt) to 0
        for (i = 0; i < numcols; i++) {
            rt[i] = 0;
        }

        // Step 2: Count the number of non-zero elements in each column
        for (i = 1; i <= numterms; i++) {
            rt[a[i].c]++;
        }

        // Step 3: Compute starting positions (sp) for each column
        sp[0] = 1;
        for (i = 1; i < numcols; i++) {
            sp[i] = sp[i - 1] + rt[i - 1];
        }

        // Step 4: Place elements into the transposed matrix
        for (i = 1; i <= numterms; i++) {
            j = sp[a[i].c]++;
            t[j].r = a[i].c;
            t[j].c = a[i].r;
            t[j].v = a[i].v;
        }
    }
}

// Main function to test the transpose
int main() {
    term a[10], t[10]; // Arrays to hold the original and transposed matrix
    int i;

    // Input the sparse matrix in tuple form
    printf("\nEnter the number of rows and columns: ");
    scanf("%d%d", &a[0].r, &a[0].c);
    printf("\nEnter the number of non-zero values: ");
    scanf("%d", &a[0].v);

    for (i = 1; i <= a[0].v; i++) {
        printf("\nEnter %dth row, column, and value: ", i);
        scanf("%d%d%d", &a[i].r, &a[i].c, &a[i].v);
    }

    // Display the original matrix in tuple form
    printf("\nOriginal Matrix in Tuple Form:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 1; i <= a[0].v; i++) {
        printf("%d\t%d\t%d\n", a[i].r, a[i].c, a[i].v);
    }

    // Perform the transpose
    transpose(a, t);

    // Display the transposed matrix in tuple form
    printf("\nTransposed Matrix in Tuple Form:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 1; i <= t[0].v; i++) {
        printf("%d\t%d\t%d\n", t[i].r, t[i].c, t[i].v);
    }

    return 0;
}
