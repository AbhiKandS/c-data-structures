#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "src/stack.h"
#include "src/hasht.c"

//bool isOperator(char ch)

int isHigherPrecidence(hasht* hasht, char* op1, char* op2) {
    int one = atoi(hasht->lookup(hasht, op1));
    int two = atoi(hasht->lookup(hasht, op2));
    return one > two;
}

bool lrAssociative(char op) {
    return (op == '^');
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
        if (isHigherPrecidence(o, &ch, &(stack1.peek(stack1)))) {
            stack1.push(&stack1, ch);
        }
    }
    return expression;
}

int main() {
    hasht operators = HashTable.new(90);
    hasht* o = &operators;
    operators.insert(o, "(", "4");
    operators.insert(o, ")", "4");
    operators.insert(o, "^", "3");
    operators.insert(o, "*", "2");
    operators.insert(o, "/", "2");
    operators.insert(o, "%", "2");
    operators.insert(o, "+", "1");
    operators.insert(o, "-", "1");

    infix_postfix("wh+t and-*");
}