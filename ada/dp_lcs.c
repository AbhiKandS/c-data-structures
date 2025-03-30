#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {return (a>b) ? a : b;}

int lcs(char *x, char *y) {
    if (*x == '\0' || *y == '\0') return 0;
    if (*x == *y) return 1+lcs(x+1, y+1);
    else return max(lcs(x+1,y), lcs(x,y+1));
}

int dp_lcs(char *x, char *y, int i, int j, int **t) {
    if (i == 0 || j == 0) 
        return (x[i] == y[j]) ? 1 : 0;

    if (x[i] == y[j]) {
        if (t[i-1][j-1] == -1) t[i-1][j-1] = dp_lcs(x,y,i-1,j-1,t);
        return 1 + t[i-1][j-1];
    }

    else {
        if (t[i-1][j] == -1)
            t[i - 1][j] = dp_lcs(x,y,i-1, j,t);
        if (t[i][j-1] == -1)
            t[i][j - 1] = dp_lcs(x,y,i,j-1,t);
        return max(t[i-1][j], t[i][j-1]);
    }
}

int dp_lcs2 (char *x, char *y, int i, int j, int **t) {
    if (i < 0 || j < 0)
        return 0;
    if (t[i][j] == -1)
    {
        if (x[i] == y[j]) t[i][j] = 1 + dp_lcs2(x, y, i - 1, j - 1, t);

        else t[i][j] = max(dp_lcs2(x,y,i-1,j,t), dp_lcs2(x,y,i,j-1,t));
    }

    return t[i][j];
}

int dpLcs(char *x, char *y)
{
    int i = strlen(x);
    int j = strlen(y);
    int **table = (int **)malloc(i * sizeof(int *));
    for (int a = 0; a < i; a++) table[a] = (int *)malloc(j * sizeof(int));

    for (int a = 0; a < i; a++)
        for (int b = 0; b < j; b++)
            table[a][b] = -1;

    return dp_lcs2(x,y,i-1,j-1, table);
}

int main() {
    char *x = "abcde";
    char *y = "ace";
    printf("Length of Least Common %d\n", dpLcs(x, y));
    return 0;
}