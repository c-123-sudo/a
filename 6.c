// Write a C program to implement multiple linked stacks (at least 5) and perform the following operations 
//  on them 
// (i) Push an item in i th stack     (ii) Pop an item from i th stack   (iii) Display i th stack 
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct stackNode{
        element data;
        struct stackNode *link;
}stackNode;
typedef stackNode *stackPointer;
int IS_EMPTY(stackPointer top){
        return top==NULL;
lude<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct stackNode{
        element data;
        struct stackNode *link;
}stackNode;
typedef stackNode *stackPointer;
int IS_EMPTY(stackPointer top){
        return top==NULL;
}
int IS_FULL(stackPointer temp)
{
        return temp==NULL;
}
void add(stackPointer *top,element item)
{
        stackPointer temp=(stackPointer)malloc(sizeof(stackNode));
        if(IS_FULL(temp))
        {
                fprintf(stderr, "the memory if full\n");
                exit(1);
        }
        temp->data=item;//set the data for the new node 
        temp->link=*top;//
        *top=temp;
}
element delete(stackPointer *top){
        if (IS_EMPTY(*top))
        {
                fprintf(stderr, "The stack is empty\n");
             }
int IS_FULL(stackPointer temp)
{
        return temp==NULL;
}
void add(stackPointer *top,element item)
{
        stackPointer temp=(stackPointer)malloc(sizeof(stackNode));
        if(IS_FULL(temp))
        {
                fprintf(stderr, "the memory if full\n");
                exit(1);
        }
        temp->data=item;//set the data for the new node 
        temp->link=*top;//
        *top=temp;
}
element delete(stackPointer *top){
        if (IS_EMPTY(*top))
        {
                fprintf(stderr, "The stack is empty\n");
                exit(1);
        }
        stackPointer temp=*top;
        element item = temp->data;
        *top= temp->link;
        free(temp);
        return item;
}
void print_stack(stackPointer top){
        printf("Stack:");
        while (top!=NULL)
        {
                printf("%d",top->data);
                top=top->link;
        }
        printf("\n");
}
int main()
{
        stackPointer top=NULL;
        add(&top,10);//add some element to the top
        add(&top,20);
        add(&top,30);
        print_stack(top);

        printf("Popped element: %d\n", delete(&top));

        print_stack(top);
        add(&top,40);
        add(&top,50);
        print_stack(top);
        while(!IS_EMPTY(top)){
                printf("Popped element: %d\n", delete(&top));
        }
        return 0;
}
