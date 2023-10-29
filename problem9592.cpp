#include <stdio.h>
#define MOD_NUM 1000000007

typedef unsigned long long llu;

int main()
{
    int n;
    llu k;

    scanf("%d%llu", &n, &k);
    llu res = 1;

    int lastProduct = n % 2 ? n - 1 : k * n / 2 + n / 2 - 1;
    int pow = (n + 1) / 2;

    k %= MOD_NUM;

    for (; pow; pow >>= 1)
    {
        if (pow & 1)
            res = res * k % MOD_NUM;

        k = k * k % MOD_NUM;
    }

    res = (res * lastProduct) % MOD_NUM;

    printf("%llu", res);
}