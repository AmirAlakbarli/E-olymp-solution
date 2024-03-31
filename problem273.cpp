#include <stdio.h>

int main()
{
    long long x;
    int n, m;
    scanf("%lld%d%d", &x, &n, &m);
    long long res = 1;
    while (n)
    {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }

    printf("%lld", res);
}