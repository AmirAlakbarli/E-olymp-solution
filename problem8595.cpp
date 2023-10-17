#include <stdio.h>
#include <cmath>

#define MOD_NUM 1000000007

int main()
{
    unsigned long n, m;
    unsigned long long res = 1;
    scanf("%lu%lu", &n, &m);
    if (abs(n - m) >= 2)
        res = 0;
    else if (abs(n - m) == 1)
    {
        for (int i = n, j = m; i > 0 && j > 0; i--, j--)
        {
            res = (res * i) % MOD_NUM;
            res = (res * j) % MOD_NUM;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            res = (res * i) % MOD_NUM;
            res = (res * i) % MOD_NUM;
        }
        res = (res * 2) % MOD_NUM;
    }

    printf("%llu", res);
}
