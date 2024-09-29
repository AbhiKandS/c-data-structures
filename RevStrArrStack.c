#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int max, tos = -1;
char *stack;

bool push(char data)
{
    if (tos == max - 1) return false;
    stack[++tos] = data;
    return true;
}

char pop()
{
    if (tos == -1) return '\0';
    return stack[tos--];
}

char *scan_string(char *prompt)
{
    printf("%s", prompt);
    int i = 0, size = 1;
    char c;
    char *buffer = (char *)malloc(size * sizeof(char *));
    if (!buffer) return NULL;

    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (i > size)
        {
            size = size * 2;
            buffer = realloc(buffer, size);
            if (!buffer) return NULL;
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    buffer = realloc(buffer, i + 1);
    return buffer;
}

char* reverse(char *str)
{
    max = strlen(str);
    stack = realloc(stack, max * sizeof(char));
    for (int i = 0; push(str[i]); i++) ;
    for (int i = 0; (str[i] = pop()); i++) ;
    return str;
}

int main()
{
    char *s = scan_string("Enter a string: ");
    printf("Reversed string: %s\n", reverse(s));
}