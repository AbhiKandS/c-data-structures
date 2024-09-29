#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* new_node(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

node *front = NULL, *rear = NULL;
int count = 0;

void enqueue(int data) {
    node* new = new_node(data);
    if (!front && !rear) {
        front = rear = new;
    }
    else {
        rear->next = new;
        rear = new;
    }
    printf("Enqueued %d\n", data);
    count++;
}

void dequeue() {
    if (!front) printf("Empty queue\n");
    else {
        node *temp = front;

        front = front->next;
        free(temp);
        temp = NULL;
        count--;
    }
}

void peek() {
    if (!front) printf("Empty queue\n");
    else {
        printf("Front element: %d\n", front->data);
    }
}

void display() {
    if (!front) printf("Empty queue\n");
    else {
        node* temp = front;
        printf("queue: ");
        while(temp) {
            printf("%d ", temp->data);
            temp = temp->next;
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
    enqueue(value);
            break;
        
        case 2:
            dequeue();
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
