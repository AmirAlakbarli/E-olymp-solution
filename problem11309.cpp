#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    if (n > 123456789)
        printf("0");
    else
        printf("1");
}