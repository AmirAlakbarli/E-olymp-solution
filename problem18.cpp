#include <stdio.h>

int main()
{
    int a, b, res = 4;
    scanf("%d%d", &a, &b);

    if (b > a)
    {
        b ^= a ^= b ^= a;
    }

    while (a > 4)
    {
        a = (a + 2) / 3;
        res += 6;
    }

    if (a == 4)
        res += 6;
    else if (a == 3)
        res += 4;
    else if (a == 2)
        res += 2;

    while (b > 4)
    {
        b = (b + 2) / 3;
        res += 6;
    }
    if (b == 4)
        res += 8;
    else if (b == 3)
        res += 6;
    else if (b == 2)
        res += 4;

    printf("%d", res);
}