#include "src/stack.c"
#include <stdarg.h>

int main() {
    int c = 1, d = 2, e = 4;
    c = (d = e);
    printf("%d\n", c);
}