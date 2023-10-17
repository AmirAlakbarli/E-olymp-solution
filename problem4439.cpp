#include <stdio.h>

long pow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        long y = pow(x, n / 2);
        return y * y;
    }
    else
    {
        return x * pow(x, n - 1);
    }
}

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);

    long res = pow(x, n);
    printf("%ld", res);
}