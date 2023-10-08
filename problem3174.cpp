#include <stdio.h>

using namespace std;

typedef unsigned long long llu;

const int mod = 1000003;
llu dp[1000][1000];
int bpoint = 0;

void Delannoy(int n, int bp)
{
    for (int i = bp; i < n; i++)
        dp[i][0] = dp[0][i] = 1;

    for (int i = bp; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];
            dp[i][j] = dp[i][j] % mod;
            dp[j][i] = dp[i][j];
        }
    }
}

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        if (n > bpoint)
        {
            Delannoy(n, bpoint);
            bpoint = n;
        }
        printf("%llu\n", dp[n - 1][n - 1]);
    }
}