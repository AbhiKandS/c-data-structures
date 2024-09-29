/**
 * 6. write a program to reverse a sentence/string using stack.
 * 7. write a program to check for balanced parenthesis in a given expression.
 *  8. write a program to convert infix expression to prefix and postfix expression.
 *  9. write a program to implement linear queue using array and linkedlist.
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int front = -1;
int rear = -1;
int queue[MAX];

void enque(int data)
{
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
        printf("Enqued %d\n", data);
    }
    else {
        queue[++rear] = data;
        printf("Enqued %d\n", data);
    }
}

void deque() 
{
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else if (front == rear) {
        printf("Dequeued %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Dequeued %d\n", queue[front++]);
    }
}

void peek()
{
    if (front == -1 && rear == -1) {
        printf("Empty queue\n");
    }
    else {
        printf("front of queue: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1) {
        printf("Empty queue\n");
    }
    else {
        printf("queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice = 0;
    int value;
    do {
        printf("\n1. enqueue \n2. dequeue \n3. peek \n4. display \n0. Exit \nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enque(value);
            break;
        
        case 2:
            deque();
            break;
        
        case 3:
            peek();
            break;
        
        case 4:
        display();
        break;
        
        default:
            break;
        } 
    } while (choice);
}