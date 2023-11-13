#include <stdio.h>

int main()
{
    long long n, a;
    scanf("%lld", &n);
    if (n < 4 || n % 4 == 0 || n % 4 == 2)
        a = n / 4;
    else
        a = n / 4 - 1;
    if (a == 0 || n == 11)
        printf("-1");
    else
        printf("%lld", a);
}