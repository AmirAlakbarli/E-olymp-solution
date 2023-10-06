#include <stdio.h>

typedef unsigned long long llu;

llu gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    llu g = gcd(a, b);
    printf("%llu", a / g * b);
}