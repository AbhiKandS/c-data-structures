#include "scan.h"

char *f_string(char *format, ...)
{
    va_list args;
    char *buffer;

    va_start(args, format);
    if (vasprintf(&buffer, format, args) == -1)
        buffer = NULL;
    va_end(args);

    return buffer;
}

static int scan_integer(char *prompt)
{
    printf("%s", prompt);
    int rc, a;
    while ((rc = scanf("%d", &a)) == 0 || rc == EOF)
    {
        scanf("%*[^\n]");
        printf("%s", prompt);
    }
    return a;
}
static char *scan_string(char *prompt)
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
scan Scan = {
    .integer = scan_integer,
    .string = scan_string,
};