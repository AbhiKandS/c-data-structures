#include "src/stack.c"
#include <string.h>
#include "src/scan.h"

char* reverse(char** str) {
    int a = b;
    stack st = Stack.new();
    int len = strlen(*str);
    for (int i = 0; i < len; i++) {
        st.push(&st, (*str)[i]);
    }
    *str = st.string(&st);
    return st.string(&st);
}

int main() {
    char* s = Scan.string("Enter a string to be reversed: ");
    reverse(&s);
    printf("%s\n", s);
}