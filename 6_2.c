// Write a C program to implement multiple linked stacks (at least 5) and perform the following operations on them.
// (i) Push an item in i th stack  (ii) Pop an item from i th stack  (iii) Display i th stack

#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 5

typedef struct node {
    int data;
    struct node *link;
} Node;

Node *top[STACKSIZE];

void push(int i, int ele) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = ele;
    temp->link = top[i];
    top[i] = temp;
}

void pop(int i) {
    if (top[i]) {
        Node *temp = top[i];
        top[i] = top[i]->link;
        printf("Popped element: %d\n", temp->data);
        free(temp);
    } else {
        printf("%dth Stack is empty\n", i);
    }
}

void display() {
    for (int i = 0; i < STACKSIZE; i++) {
        if (top[i]) {
            Node *temp = top[i];
            printf("\nPrinting %dth Stack elements\n", i);
            while (temp) {
                printf("%d\t", temp->data);
                temp = temp->link;
            }
        } else {
            printf("\n%dth Stack is Empty\n", i);
        }
    }
}

int main() {
    for (int i = 0; i < STACKSIZE; i++) {
        top[i] = NULL;
    }
    int i, choice, ele;
    do {
        printf("\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter stack index (0-%d) and Element: ", STACKSIZE - 1);
                scanf("%d%d", &i, &ele);
                push(i, ele);
                break;
            case 2:
                printf("From which stack (0-%d) ? : ", STACKSIZE - 1);
                scanf("%d", &i);
                pop(i);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    } while (choice != 4);
}
