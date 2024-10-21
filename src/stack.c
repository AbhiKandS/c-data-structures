#include "stack.h" 

static struct node {
    char data;
    struct node *next;
} node;

static struct node *node_new(char data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}


    static bool stack_push(struct stack* st, char data) {
        struct node *new = node_new(data);
        if (!new) return 0;
        if (!st->tos) {
            st->tos = new;
        }
        else {
            new->next = st->tos;
            st->tos = new;
        }
        st->count++;
        return 1;
    }
    static char stack_pop(stack* st) {
        if (!st->tos) return '\0';
        struct node* temp = st->tos;
        st->tos = st->tos->next;
        char data = temp->data;
        free(temp);
        st->count--;
        return data;
    }
    static char* stack_string(stack* st) {
        char* buffer = (char*)malloc((st->count+1) * sizeof(char));
        struct node* temp = st->tos;
        int i = 0;
        while(temp) {
            buffer[i++] = temp->data;
            temp = temp->next;
        }
        buffer[i] = '\0';
        return buffer;
    }
    static char stack_peek(stack* st) {
        if (!st->tos) return '\0';
        return st->tos->data;
    }
    static void stack_clear(stack* st) {
        struct node *tmp = st->tos;
        struct node *next;
        while(tmp)
        {
            next = tmp->next;
            free(tmp);
            tmp = next;
        }
        st->tos = NULL;
    }
    static stack stack_new(void) {
        stack st = {
            .tos = NULL,
            .count = 0,
            .push = stack_push,
            .pop = stack_pop,
            .string = stack_string,
            .peek = stack_peek,
            .clear = stack_clear,
        };
        return st;
    }
stack Stack = {
    .new = stack_new,
};