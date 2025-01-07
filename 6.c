// Write a C program to implement multiple linked stacks (at least 5) and perform the following operations 
//  on them 
// (i) Push an item in i th stack     (ii) Pop an item from i th stack   (iii) Display i th stack 
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

    int choice, stackIndex, item;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Push an item onto a stack\n");
        printf("2. Pop an item from a stack\n");
        printf("3. Display a stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack index (0 to %d): ", n - 1);
                scanf("%d", &stackIndex);
                if (stackIndex < 0 || stackIndex >= n) {
                    printf("Invalid stack index\n");
                    break;
                }
                printf("Enter item to push: ");
                scanf("%d", &item);
                add(&stacks[stackIndex], item);
                break;

            case 2:
                printf("Enter stack index (0 to %d): ", n - 1);
                scanf("%d", &stackIndex);
                if (stackIndex < 0 || stackIndex >= n) {
                    printf("Invalid stack index\n");
                    break;
                }
                if (IS_EMPTY(stacks[stackIndex])) {
                    printf("Stack %d is empty\n", stackIndex);
                } else {
                    printf("Popped item: %d\n", delete(&stacks[stackIndex]));
                }
                break;

            case 3:
                printf("Enter stack index (0 to %d): ", n - 1);
                scanf("%d", &stackIndex);
                if (stackIndex < 0 || stackIndex >= n) {
                    printf("Invalid stack index\n");
                    break;
                }
                printf("Stack %d contents:\n", stackIndex);
                print_stack(stacks[stackIndex]);
                break;

            case 4:
                printf("Exiting program\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
