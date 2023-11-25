#include <stdio.h>
typedef long long ll;

ll extendedGCD(ll a, ll b, ll *x, ll *y)
{
    ll x1 = 0, y1 = 1;
    *x = 1, *y = 0;
    while (b)
    {
        ll q = a / b;
        b ^= a ^= b ^= a %= b;
        x1 ^= *x ^= x1 ^= *x -= q * x1;
        y1 ^= *y ^= y1 ^= *y -= q * y1;
    }
    return a;
}

int main()
{
    short t;
    scanf("%hd", &t);
    while (t--)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        ll x, y;
        ll g = extendedGCD(a, b, &x, &y);
        if (g > 1)
            printf("No Solution\n");
        else
        {
            if (x < 0)
            {
                ll k = -x / b + 1;
                x += k * b;
                y -= k * a;
            }
            printf("%lld %lld\n", x, y);
        }
    }
}
