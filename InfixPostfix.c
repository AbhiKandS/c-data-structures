#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stack.c"

char* infix_postfix(char* expression)
{
    stack* stack1 = new_stack();
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        char ch = expression[i];
        while (1)
        {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')' ||)
            {
                if (isEmpty(stack1) || ch == '(')
                    stack_push(stack1, ch);
                    break;
                if (ch == '+')
            }
            else
            {
                printf("%c", ch);
            }
        }
    }
}

int main() {
}