#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE st->size
#define TOS st->tos

typedef struct node
{
    int data;
    struct node* link;
} node;

typedef struct stack
{
    node* tos;
    int size;
} stack;

node* new_node(int data)
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->link = NULL;
    return new;
}

stack* new_stack()
{
    stack* st = (stack*)malloc(sizeof(stack));
    TOS = NULL;
    SIZE = 0;
    return st;
}

bool stack_push(stack* st,int data)
{
    node* new = new_node(data);
    if(!new) return 0;

    new->link = TOS;
    TOS = new;
    SIZE++;
    return 1;
}

int stack_pop(stack* st)
{
    int data = INT_MIN;
    if (!TOS) printf("Empty Stack!!");
    else
    {
        node* temp = TOS;
        data = temp->data;
        TOS = TOS->link;
        free(temp);
        temp = NULL;
    }
    return data;
}

void stack_display(stack* st)
{
    if (!TOS) printf("Empty Stack!!\n");
    else 
    {
        for (node* i = TOS; i; i = i->link)
        {
            printf("%d ", i->data);
        }
        printf("\n");
    }
    return;
}

bool isEmpty(stack* st) {return !TOS;}