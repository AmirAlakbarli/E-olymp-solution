#include <stdio.h>

int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    printf("%llu", 3 * n * (n + 1) + 1);
}