// Write a C program to implement a doubly linked circular list with a header node and perform the following operations on it. (i) Insert a node (iii) Display a doubly linked circular list in forward direction (ii) Delete a node (iv) Display a doubly linked circular list in reverse direction
#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePtr;
typedef struct node {
    nodePtr llink;
    int data;
    nodePtr rlink;
} node;

nodePtr head;

void dinsert() {
    int n;
    nodePtr temp;
    printf("Enter the info for the new node\n");
    scanf("%d", &n);
    temp = (nodePtr)malloc(sizeof(node));
    temp->data = n;
    temp->llink = head;
    temp->rlink = head->rlink;
    head->rlink->llink = temp;
    head->rlink = temp;
}

void ddelete() {
    nodePtr temp = head->rlink;
    if (head->rlink == head)
        printf("Deletion of head node not permitted.\n");
    else {
        head->rlink = temp->rlink;
        temp->rlink->llink = head;
        printf("Removing node with data %d\n", temp->data);
        free(temp);
    }
}

void displayRight() {
    nodePtr temp;
    if (head->rlink == head)
        printf("Empty list.\n");
    else {
        for (temp = head->rlink; temp->rlink != head; temp = temp->rlink)
            printf("%d\t", temp->data);
        printf("%d\t", temp->data);
        printf("\n\n");
    }
}

void displayLeft() {
    nodePtr temp;
    if (head->llink == head)
        printf("Empty list.\n");
    else {
        for (temp = head->llink; temp->llink != head; temp = temp->llink)
            printf("%d\t", temp->data);
        printf("%d\t", temp->data);
        printf("\n\n");
    }
}

int main() {
    unsigned int choice;
    head = (nodePtr)malloc(sizeof(node));
    head->rlink = head;
    head->llink = head;

    while (1) {
        printf("\n1: Insert a node in DLL\n");
        printf("2: Delete a node from DLL\n");
        printf("3: Display the DLL Backward\n");
        printf("4: Display the DLL Forward\n");
        printf("5: Exit\n");
        scanf("%u", &choice);
        switch (choice) {
            case 1:
                dinsert();
                break;
            case 2:
                ddelete();
                break;
            case 3:
                displayRight();
                break;
            case 4:
                displayLeft();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice... try again\n");
        }
    }
    return 0;
}
