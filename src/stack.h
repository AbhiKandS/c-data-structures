#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>

typedef struct stack {
    struct node* tos;
    int count;
    struct stack (*new)(void);
    char (*pop)(struct stack*);
    bool (*push)(struct stack*, char);
    char (*peek)(struct stack*);
    char* (*string)(struct stack*);
    void (*clear)(struct stack*);
} stack;

extern stack Stack;

#endif // STACK_H