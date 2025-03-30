#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "src/stack.h"

void strrev(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool lrAssociative(char op) {
    return (op == '^');
}

bool isOperand(char ch) {
    return !(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '(' || ch == ')');
}

void infix_prefix(char *expression)
{
    strrev(expression);  

    stack stack1 = Stack.new();
    stack target = Stack.new();
    int len = strlen(expression);
    char *ch = expression;

    
    while (*ch)
    {
        if (isOperand(*ch))  
        {
            target.push(&target, *ch);
            ch++;
        }
        else if (*ch == ')')  
        {
            stack1.push(&stack1, *ch);
            ch++;
        }
        else if (*ch == '(')  
        {
            char x;
            while ((x = stack1.pop(&stack1)) != ')')
            {
                target.push(&target, x);
            }
            ch++;
        }
        else  
        {
            while (stack1.count > 0 && precedence(stack1.peek(&stack1)) >= precedence(*ch))
            {
                target.push(&target, stack1.pop(&stack1));
            }
            stack1.push(&stack1, *ch);
            ch++;
        }
    }

    while (stack1.count != 0) {
        target.push(&target, stack1.pop(&stack1));
    }

    char* result = target.string(&target);
    printf("%s\n", result);
}

int main()
{
    char expression[] = "a+b*(c-d)/(e*f+g)*h^i^j";
    printf("Infix expression: %s\n", expression);
    printf("Prefix expression: ");
    infix_prefix(expression);

    return 0;
}
