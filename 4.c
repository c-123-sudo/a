 
// Write a C program to implement a circular queue using dynamically allocated array and perform the  
// following operations on it. 
// (i) Insert an item    (ii) Delete an item             (iii) Display a circular queue 
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int *arr;
    int front, rear;
    int size;
} CircularQueue;

void initQueue(CircularQueue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    if (q->arr == NULL) {
        printf("Memory Allocation failed\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    q->size = size;
}

int isFull(CircularQueue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void insertItem(CircularQueue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert item.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = item;
    printf("Inserted %d into the queue.\n", item);
}

void deleteItem(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete item.\n");
        return;
    }
    int deletedItem = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    printf("Deleted %d from the queue.\n", deletedItem);
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Circular Queue elements:");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[q->rear]);
}

void freeQueue(CircularQueue *q) {
    free(q->arr);
}

int main() {
    CircularQueue q;
    int size;
    printf("Enter the size of the circular queue:");
    scanf("%d", &size);
    initQueue(&q, size);
    int choice, item;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1.Insert an item\n");
        printf("2.Delete an item\n");
        printf("3.Display the queue\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to insert:");
                scanf("%d", &item);
                insertItem(&q, item);
                break;
            case 2:
                deleteItem(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    freeQueue(&q);
    return 0;
 }
//============output:
// mlds25@ritserver:~$ vi circular.c
// mlds25@ritserver:~$ cc circular.c
// mlds25@ritserver:~$ ./a.out
// Enter the size of the circular queue:5

// Circular Queue Operations:
// 1.Insert an item
// 2.Delete an item
// 3.Display the queue
// 4.Exit
// Enter your choice:1
// Enter item to insert:10
// Inserted 10 into the queue.

// Circular Queue Operations:
// 1.Insert an item
// 2.Delete an item
// 3.Display the queue
// 4.Exit
// Enter your choice:1
// Enter item to insert:20
// Inserted 20 into the queue.

// Circular Queue Operations:
// 1.Insert an item
// 2.Delete an item
// 3.Display the queue
// 4.Exit
// Enter your choice:3
// Circular Queue elements:10 20

// Circular Queue Operations:
// 1.Insert an item
// 2.Delete an item
// 3.Display the queue
// 4.Exit
// Enter your choice:2
// Deleted 10 from the queue.

// Circular Queue Operations:
// 1.Insert an item
// 2.Delete an item
// 3.Display the queue
// 4.Exit
// Enter your choice:3
// Circular Queue elements:20

// Circular Queue Operations:
// 1.Insert an item
// 2.Delete an item
// 3.Display the queue
// 4.Exit
// Enter your choice:4
// Exiting program.
