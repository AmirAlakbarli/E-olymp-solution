#include <stdio.h>
typedef long long ll;

int main()
{
    __int128_t a;
    ll b, m, res = 1;
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