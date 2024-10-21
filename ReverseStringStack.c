#include "src/stack.h"
#include <string.h>
#include "src/scan.h"

char* reverse(char** str) {
    stack st = Stack.new();
    int len = strlen(*str);
    for (int i = 0; i < len; i++) {
        st.push(&st, (*str)[i]);
    }
    for (int i = 0; ((*str)[i] = st.pop(&st)); i++)

    return (*str);
}

int main() {
    char* s = Scan.string("Enter a string to be reversed: ");
    reverse(&s);
    printf("%s\n", s);
}