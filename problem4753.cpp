#include <stdio.h>

int gcd(int a, int b)
{
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", gcd(n - 1, m - 1) + 1);
}