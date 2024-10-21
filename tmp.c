#include <stdio.h>

int main() {
    char* c = "what";
    char* d = c;
    ++d;
    printf("%s\n", d);
}