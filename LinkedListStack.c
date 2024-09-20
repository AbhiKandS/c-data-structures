#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *link;
} node;

node *new_node(int data)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = data;
    new->link = NULL;
    return new;
}

node *TOS = NULL;
int size = 0;

bool isEmpty() { return !TOS; }

void push(int data)
{
    node *new = new_node(data);
        new->link = TOS;
        TOS = new;
    printf("%d pushed to stack\n", TOS->data);
    size++;
}

void pop()
{
    if (!TOS)
    {
        printf("Empty Stack!\n");
    }
    else
    {
        node *temp = TOS;
        int result = temp->data;
        TOS = TOS->link;
        free(temp);
        size--;
        printf("%d poped from stack\n", result);
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("Empty Stack!\n");
        return INT_MIN;
    }
    else
    {
        printf("Data at top of stack: %d\n", TOS->data);
        return TOS->data;
    }
}

void display()
{
    if (isEmpty())
        printf("Empty Stack!\n");
    else
    {
        node *temp = TOS;
        printf("Stack: ");
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int get_int(char prompt[])
{
    int result;
    printf("%s", prompt);
    scanf("%d", &result);
    return result;
}

int main()
{
    int choice;
    do
    {
        printf("\n");
        printf("1. Push \n2. Pop \n3. Peek \n4. Display \n0. Exit \nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(get_int("Enter number to push: "));
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
        default:
            break;
        }
    } while (choice);
}