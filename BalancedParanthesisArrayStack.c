#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

int max = 100, tos = -1;
int stack[100];

bool push(int data)
{
    if (tos == max - 1) return false;
    stack[++tos] = data;
    return true;
}

void pop()
{
    if (tos != -1) tos--;
}

char *scan_string(char *prompt)
{
    printf("%s", prompt);
    int i = 0, size = 1;
    char *buffer = (char *)malloc(size * sizeof(char *));
    char c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (i + 1 > size)
        {
            size = size * 2;
            buffer = realloc(buffer, size);
        }

        buffer[i++] = c;
    }
    buffer[i] = '\0';
    buffer = realloc(buffer, i + 1);
    return buffer;
}

bool isBalanced(char* str)
{
   for (int i = 0; str[i] ; i++)
   {
    if (str[i] == '(') push(1);
    if (str[i] == ')')
    {
        if (tos == -1) return 0;
        pop();
    } 
   }
   return tos == -1;
}

int main()
{
    char* str = scan_string("Enter an expression: ");
    if (isBalanced(str)) printf("The paranthesis in the expression is balanaced");
    else printf("The paranthesis in the expression is not balanaced");
}