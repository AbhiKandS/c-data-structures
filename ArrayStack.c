#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int stack[MAX];
int TOS = -1;

int get_int(char prompt[]) {
    int result;
    printf("%s", prompt);
    scanf("%d", &result);
    return result;
}

bool isEmpty() {
    return TOS == -1;
}

bool isFull() { return TOS == MAX-1;}

void push(int data) {
    if (isFull()) printf("Stock Overflow\n");
    else {
        stack[TOS+1] = data;
        TOS++;
        printf("Pushed %d to stack\n", data);
    }
}

void pop() {
    if (isEmpty()) printf("Stack Underflow\n");
    else {
        TOS--;
        printf("Poped %d from stack\n", stack[TOS+1]);
    }
}

void peek() {
    if (isEmpty()) printf("Empty Stack\n");
    else {
        printf("Top of Stack contains %d\n", stack[TOS]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Emtpy stack");
        return;
    }
    printf("Stack contains: \n");
    for (int i = 0; i <= TOS; i++) {
        printf("%d \n", stack[TOS-i]);
    }
}

int main() {
    int choice;
    do {
        choice = get_int("\nChoose from the following operations: \n1: push\n2: pop\n3. peek\n4. display\n5. isEmpty\n6. isFull\n0. Exit\n");

        switch (choice)
        {
        case 1:
            push(get_int("Enter element to push: \n"));
            break;
        
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("%s\n", isEmpty() ? "true" : "false");
            break;
        case 6:
            printf("%s\n", isFull() ? "true" : "false");
            break;
        
        default:
            break;
        }
    }while(choice);
}