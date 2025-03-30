#include "src/stack.c"
#include "src/scan.c"
#include <stdbool.h>
#include <stdarg.h>


bool isBalanced(char* str)
{
   stack new = Stack.new();
   for (int i = 0; str[i] ; i++)
   {
    if (str[i] == '(') new.push(&new, '(');
    if (str[i] == ')')
    {
        if (new.tos == NULL) return 0;
        new.pop(&new);
    } 
   }
   printf("%s\n", new.string(&new));
   return new.tos == NULL;
}

int main()
{
    printf("%d", (int)isBalanced(Scan.string(": ")));
}