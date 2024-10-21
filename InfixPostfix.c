#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "src/stack.h"
#include "src/hasht.c"

int precedence(char op)
{
    if (op == '(' || op == ')') return 4;
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool lrAssociative(char op) {
    return !(op == '^');
}

bool isOperand(char ch) {
    return !(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '(' || ch == ')');
}

char* infix_postfix(char* expression)
{
    stack stack1 = Stack.new();
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        if (isOperand(ch)) {
            printf("%c", ch);
            continue;
        }
        if (stack1.peek(&stack1) == '(' || stack1.count == 0) {
            stack1.push(&stack1, ch);
            continue;
        }
        if (stack1.peek(&stack1) == ')')
        {
            char x;
            while ((x = stack1.pop(&stack1)) != '(') {
                printf("%c", x);
            }
        }
    }
    printf("\n");
    printf("%s\n", stack1.string(&stack1));
    return expression;
}

int main() {
    infix_postfix("a+b(b-)");
}
