#include "src/stack.c"
#include "src/scan.c"
#include <stdbool.h>
#include <stdarg.h>

#define I(obj, method, ...) (obj.method(&obj, __VA_ARGS__))

bool isBalanced(char* str)
{
   stack new = Stack.new();
   for (int i = 0; str[i] ; i++)
   {
    if (str[i] == '(') new.push(&new, 1);
    if (str[i] == ')')
    {
        if (!new.peek(&new)) return 0;
        new.pop(&new);
    } 
   }
   return 1;
}

int main()
{
    printf("%d", (int)isBalanced(Scan.string(": ")));
}