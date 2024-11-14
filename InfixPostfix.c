#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "src/stack.h"
#include "src/scan.h"

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

void infix_postfix(char *expression)
{
    stack stack1 = Stack.new();
    int len = strlen(expression);
    char *ch = expression;
    while (*ch)
    {
        if (isOperand(*ch))
        {
            printf("%c", *ch);
            ch++;
            continue;
        }
        if (*ch == '(')
        {
            stack1.push(&stack1, *ch);
            ch++;
            continue;
        }
        if (*ch == ')')
        {
            char x;
            while ((x = stack1.pop(&stack1)) != '(')
            {
                printf("%c", x);
            }
            ch++;
            continue;
        }
        if (stack1.peek(&stack1) == '(' || stack1.count == 0)
        {
            stack1.push(&stack1, *ch);
            ch++;
            continue;
        }

        int tos = precedence(stack1.peek(&stack1));
        int curr = precedence(*ch);

        if (tos < curr)
        {
            stack1.push(&stack1, *ch);
            ch++;
            continue;
        }

        if (tos > curr || (tos == curr && lrAssociative(*ch)))
        {
            printf("%c", stack1.pop(&stack1));
            continue;
        }
        else
        {
            stack1.push(&stack1, *ch);
            ch++;
            continue;
        }
    }
    printf("%s\n", stack1.string(&stack1));
}

int main()
{
    char* expression = "a+b*(c-d)/(e*f+g)*h^i^j";
    infix_postfix(expression);
}