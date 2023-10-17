#include <stdio.h>

int main()
{
    unsigned long long floors;
    scanf("%llu", &floors);
    printf("%llu", floors * (3 * floors + 1) / 2);
}