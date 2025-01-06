// Write a C program to add two polynomials represented as circular linked lists with header nodes. 
// Display both polynomials and the resultant polynomial after addition.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node* header, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (header->next == header) {
        header->next = newNode;
        newNode->next = header;
        return;
    }
    
    struct Node* current = header->next;
    struct Node* prev = header;
    
    while (current != header && current->exp > exp) {
        prev = current;
        current = current->next;
    }
    
    if (current != header && current->exp == exp) {
        current->coeff += coeff;
        free(newNode);
        return;
    }
    
    prev->next = newNode;
    newNode->next = current;
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = createNode(0, 0);
    result->next = result;
    
    struct Node* p1 = poly1->next;
    struct Node* p2 = poly2->next;
    
    while (p1 != poly1) {
        insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    
    while (p2 != poly2) {
        insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    
    return result;
}

void displayPolynomial(struct Node* header) {
    struct Node* current = header->next;
    while (current != header) {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        if (current != header) printf(" + ");
    }
    printf("\n");
}

void inputPolynomial(struct Node* poly) {
    int terms, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &terms);
    
    for(int i = 0; i < terms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i+1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(poly, coeff, exp);
    }
}

int main() {
    struct Node* poly1 = createNode(0, 0);
    struct Node* poly2 = createNode(0, 0);
    poly1->next = poly1;
    poly2->next = poly2;
    
    printf("Enter first polynomial:\n");
    inputPolynomial(poly1);
    
    printf("\nEnter second polynomial:\n");
    inputPolynomial(poly2);
    
    printf("\nFirst polynomial: ");
    displayPolynomial(poly1);
    
    printf("Second polynomial: ");
    displayPolynomial(poly2);
    
    struct Node* result = addPolynomials(poly1, poly2);
    printf("Result: ");
    displayPolynomial(result);
    
    return 0;
}
