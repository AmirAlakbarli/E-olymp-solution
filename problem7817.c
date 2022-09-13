#include <stdio.h>

int main()
{
    unsigned int n;
    scanf("%u", &n);
    printf("%llu", (unsigned long long)pow(5, n));
}