#include <stdio.h>

long long f(long long x, long long n, long long m)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return f(((x * x) % m), n / 2, m);
    return x * f(x, n - 1, m) % m;
}

int main()
{
    long long x, n, m;
    scanf("%lld %lld", &n, &m);
    long long res = (f(1, n, m) + f(2, n, m)) % m;

    for (int i = 3; i <= 100; i++)
    {
        res = (res + (i - 1) * f(i, n, m)) % m;
    }
    printf("%lld", res);
}