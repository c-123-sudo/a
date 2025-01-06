// Write a C program to evaluate a given postfix expression using a stack. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// Function to push an element to the stack
void push(int data) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = data;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to calculate the result of two operands and an operator
int result(int op1, int op2, char operator) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '/': 
            if (op2 == 0) {
                printf("Division by zero error\n");
                exit(1);
            }
            return op1 / op2;
        case '%': 
            if (op2 == 0) {
                printf("Modulo by zero error\n");
                exit(1);
            }
            return op1 % op2;
        case '*': return op1 * op2;
        default: 
            printf("Invalid operator: %c\n", operator);
            exit(1);
    }
}

// Function to evaluate the postfix expression
int postfixeval(char *str) {
    int op1, op2;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            push(str[i] - '0');  // Convert character to integer and push
        } else {
            op2 = pop();
            op1 = pop();
            push(result(op1, op2, str[i]));
        }
    }
    return pop();
}

// Main function
int main() {
    char str[100];
    printf("Enter the postfix expression: ");
    scanf("%s", str);
    printf("Result after evaluation = %d\n", postfixeval(str));
    return 0;
}
==============output:
mlds25@ritserver:~$ vi postfix.c
mlds25@ritserver:~$ cc postfix.c
mlds25@ritserver:~$ ./a.out
Enter the postfix expression: 231*+9-
Result after evaluation = -4
