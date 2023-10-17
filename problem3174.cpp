#include <stdio.h>

typedef unsigned long long llu;

const int mod = 1000003;
llu dp[1000], DelNums[1000];
int bpoint = 0;

void Delannoy(int n)
{
    int endPoint = bpoint + n;
    for (int i = 0; i < n; i++)
    {
        int temp = dp[0];
        dp[0] = 1;
        int j = 0;

        while (j < bpoint + i)
        {
            if (j > 0)
            {
                int temp1 = dp[j];
                dp[j] = dp[j - 1] + dp[j] + temp;
                dp[j] %= mod;
                temp = temp1;
            }

            j++;
        }

        if (j == 0)
        {
            DelNums[j] = dp[j];
            continue;
        }

        dp[j] = 2 * dp[j - 1] + DelNums[j - 1];
        dp[j] %= mod;
        DelNums[j] = dp[j];
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
            Delannoy(n - bpoint);
            bpoint = n;
        }
        printf("%llu\n", DelNums[n - 1]);
    }
}