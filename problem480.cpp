#include <stdio.h>

int main()
{
    __int128_t a;
    long long b, m, res = 1;
    scanf("%lld %lld %lld", &a, &b, &m);

    while (b)
    {
        if (b & 1)
            res = res * a % m;

        a = a * a % m;
        b >>= 1;
    }

    printf("%lld", res);
}