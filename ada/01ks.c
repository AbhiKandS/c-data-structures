#include <stdio.h>
#include <string.h>

int knapsack(int M, int wt[], int p[], int n, int dp[n+1][M+1]) {
    if (n == 0 || M == 0)
        return 0;
    
    if (dp[n][M] != -1)
        return dp[n][M];
    
    if (wt[n - 1] > M)
        dp[n][M] = knapsack(M, wt, p, n - 1,dp);
    else
        dp[n][M] = 
            (p[n - 1] + knapsack(M - wt[n - 1], wt, p, n - 1,dp)) > 
            knapsack(M, wt, p, n - 1,dp) ?
            (p[n - 1] + knapsack(M - wt[n - 1], wt, p, n - 1,dp)) :
            knapsack(M, wt, p, n - 1,dp);
    return dp[n][M];
}

int main() {
    int p[] = {5,3,4};
    int wt[] = {3,2,1};
    int M = 10;
    int n = sizeof(p) / sizeof(p[0]);

    int dp[n+1][M+1];
    
    memset(dp, -1, sizeof(dp));
    
    printf("Maximum value in Knapsack = %d\n", knapsack(M, wt, p, n,dp));
    return 0;
}