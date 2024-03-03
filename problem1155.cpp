#include <stdio.h>

int extendedGCD(int a, int b, int *x, int *y)
{
    int x1 = 0, y1 = 1;
    *x = 1, *y = 0;
    while (b)
    {
        int q = a / b;
        b ^= a ^= b ^= a %= b;
        x1 ^= *x ^= x1 ^= *x -= q * x1;
        y1 ^= *y ^= y1 ^= *y -= q * y1;
    }
    return a;
}

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int x, y;
        int g = extendedGCD(a, b, &x, &y);
        printf("%d %d %d\n", x, y, g);
    }
}
