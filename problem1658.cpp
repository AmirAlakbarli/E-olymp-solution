#include <stdio.h>

typedef unsigned long long llu;

int main()
{
    short n;
    scanf("%hu", &n);
    llu res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    printf("%llu", res);
}