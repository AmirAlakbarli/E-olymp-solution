#include <stdio.h>
#include <math.h>
#define MOD_NUM 1000000007

long long powmod(long long x, long long n, long long m)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return powmod((x * x) % m, n / 2, m);
    return (x * powmod(x, n - 1, m)) % m;
}

int main()
{
    int n, k;
    long long res = 0;
    scanf("%d %d", &n, &k);
    for (int l = 1; l < n; l++)
        res = (res + powmod(k, (l + 1) / 2, MOD_NUM) * powmod(k, (n - l + 1) / 2, MOD_NUM)) % MOD_NUM;
    printf("%lld\n", res);
}