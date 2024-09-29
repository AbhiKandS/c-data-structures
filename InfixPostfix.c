#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "src/stack.c"
#include "src/hasht.c"

//bool isOperator(char ch)

int isHigherPrecidence(hasht* hasht, char* op1, char* op2) {
    int one = atoi(hasht->lookup(hasht, op1));
    int two = atoi(hasht->lookup(hasht, op2));
    return one > two;
}
//char* infix_postfix(char* expression)
//{
//    stack* stack1 = new_stack();
//    int len = strlen(expression);
//    for (int i = 0; i < len; i++) {
//        char ch = expression[i];
//        while (1)
//        {
//            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')' ||)
//            {
//                if (isEmpty(stack1) || ch == '(')
//                    stack_push(stack1, ch);
//                    break;
//                if (ch == '+')
//            }
//            else
//            {
//                printf("%c", ch);
//            }
//        }
//    }
//}
//
int main() {
    hasht operators = HashTable.new(30);
    hasht* o = &operators;
    operators.insert(o, "(", "4");
    operators.insert(o, ")", "4");
    operators.insert(o, "^", "3");
    operators.insert(o, "*", "2");
    operators.insert(o, "/", "2");
    operators.insert(o, "%", "2");
    operators.insert(o, "+", "1");
    operators.insert(o, "-", "1");

    printf("%d", isHigherPrecidence(o, "*", "^"));
}