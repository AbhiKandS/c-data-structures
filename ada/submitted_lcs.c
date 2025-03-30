#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {return (a>b) ? a : b;}

int dp_lcs2 (char *x, char *y, int i, int j, int t[i][j]) {
    if (i < 0 || j < 0)
        return 0;
    if (t[i][j] == -1)
    {
        if (x[i] == y[j]) t[i][j] = 1 + dp_lcs2(x, y, i - 1, j - 1, t);

        else t[i][j] = max(dp_lcs2(x,y,i-1,j,t), dp_lcs2(x,y,i,j-1,t));
    }

    return t[i][j];
}

int main() {
    char *x = "AGGRAB";
    char *y = "AGRADAB";

    int i = strlen(x);
    int j = strlen(y);

    int table[i+1][j+1];

    memset(table, -1, sizeof(table));
    int a = dp_lcs2(x,y,i-1,j-1, table);

    printf("Length of Longest Common Subsequence of \"%s\" and \"%s\" is: %d\n", x, y, a);
    return 0;
}