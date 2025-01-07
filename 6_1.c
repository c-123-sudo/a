#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct stackNode {
    element data;
    struct stackNode *link;
} stackNode;

typedef stackNode *stackPointer;

// Function to check if a stack is empty
int IS_EMPTY(stackPointer top) {
    return top == NULL;
}

// Function to check if memory allocation failed
int IS_FULL(stackPointer temp) {
    return temp == NULL;
    
}

// Function to push an item onto the stack
void add(stackPointer *top, element item) {
    stackPointer temp = (stackPointer)malloc(sizeof(stackNode));
    if (IS_FULL(temp)) {
        fprintf(stderr, "The memory is full\n");
        exit(1);
    }
    temp->data = item; // Set the data for the new node
    temp->link = *top; // Point to the previous top
    *top = temp;       // Update top to the new node
}

// Function to pop an item from the stack
element delete(stackPointer *top) {
    if (IS_EMPTY(*top)) {
        fprintf(stderr, "The stack is empty\n");
        exit(1);
    }
    stackPointer temp = *top;
    element item = temp->data;
    *top = temp->link; // Move top to the next node
    free(temp);        // Free the popped node
    return item;
}

// Function to print the elements of a stack
void print_stack(stackPointer top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->link;
    }
    printf("\n");
}

int main() {
    int n = 5; // Number of stacks
    stackPointer stacks[n]; // Array of stack pointers
    for (int i = 0; i < n; i++) {
        stacks[i] = NULL; // Initialize all stacks to NULL
    }

    // Hardcoded operations
    printf("Performing hardcoded operations...\n");

    // Push operations
    add(&stacks[0], 10);
    add(&stacks[0], 20);
    add(&stacks[1], 3);
    add(&stacks[2], 40);
    add(&stacks[3], 50);

    // Display stacks after push
    for (int i = 0; i < n; i++) {
        printf("Stack %d contents: ", i);
        print_stack(stacks[i]);
    }

    // Pop operations
    printf("\nPopping from stacks...\n");
    printf("Popped from stack 0: %d\n", delete(&stacks[0]));
    printf("Popped from stack 1: %d\n", delete(&stacks[1]));

    // Display stacks after pop
    for (int i = 0; i < n; i++) {
        printf("Stack %d contents: ", i);
        print_stack(stacks[i]);
    }

    return 0;
}
