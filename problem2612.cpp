#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int res = 0;

    while (b)
    {
        int q = a / b;
        b ^= a ^= b ^= a %= b;
        res += q;
    }
    printf("%d", res);
}