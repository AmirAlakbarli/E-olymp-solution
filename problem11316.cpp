#include <stdio.h>

long long gcd(long long a, long long b)
{
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}

int main()
{
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    long long g = gcd((a + b + c) * (a + b) * (a + c), b * c * (2 * a + b + c));
    long long p_num = b * c * (2 * a + b + c) / g;
    long long p_den = (a + b + c) * (a + b) * (a + c) / g;
    printf("%lld/%lld ", p_num, p_den);
    g = gcd((a + b + c) * (a + b) * (b + c), a * c * (a + 2 * b + c));
    p_num = a * c * (a + 2 * b + c) / g;
    p_den = (a + b + c) * (a + b) * (b + c) / g;
    printf("%lld/%lld ", p_num, p_den);
    g = gcd((a + b + c) * (a + c) * (b + c), a * b * (a + b + 2 * c));
    p_num = a * b * (a + b + 2 * c) / g;
    p_den = (a + b + c) * (a + c) * (b + c) / g;
    printf("%lld/%lld", p_num, p_den);
}
