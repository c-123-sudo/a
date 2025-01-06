// Write a C program to implement a doubly linked circular list with a header node and perform the following operations on it. (i) Insert a node (iii) Display a doubly linked circular list in forward direction (ii) Delete a node (iv) Display a doubly linked circular list in reverse direction
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insert(struct Node* header, int data, int position) {
    struct Node* newNode = createNode(data);
    
    if (header->next == header) {
        header->next = header->prev = newNode;
        newNode->next = newNode->prev = header;
        return;
    }
    
    if (position == 1) {
        newNode->next = header->next;
        newNode->prev = header;
        header->next->prev = newNode;
        header->next = newNode;
        return;
    }
    
    struct Node* current = header->next;
    int count = 1;
    
    while (count < position - 1 && current->next != header) {
        current = current->next;
        count++;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void delete(struct Node* header, int position) {
    if (header->next == header) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* current = header->next;
    int count = 1;
    
    while (count < position && current != header) {
        current = current->next;
        count++;
    }
    
    if (current == header) {
        printf("Position not found\n");
        return;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void displayForward(struct Node* header) {
    if (header->next == header) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* current = header->next;
    printf("Forward List: ");
    while (current != header) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayReverse(struct Node* header) {
    if (header->next == header) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* current = header->prev;
    printf("Reverse List: ");
    while (current != header) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    struct Node* header = createNode(0);
    header->next = header->prev = header;
    int choice, data, position;
    
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display Forward\n4. Display Reverse\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insert(header, data, position);
                break;
                
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete(header, position);
                break;
                
            case 3:
                displayForward(header);
                break;
                
            case 4:
                displayReverse(header);
                break;
                
            case 5:
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
