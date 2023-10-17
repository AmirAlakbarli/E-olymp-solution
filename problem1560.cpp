#include <stdio.h>

int n, dp[1000001];

int f(int n)
{
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = dp[i] > dp[i / 2] + 1 ? dp[i / 2] + 1 : dp[i];
        if (i % 3 == 0)
            dp[i] = dp[i] > dp[i / 3] + 1 ? dp[i / 3] + 1 : dp[i];
    }
    return dp[n];
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", f(n));
    }
}