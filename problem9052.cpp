#include <stdio.h>

int main()
{
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int second = n;

    if (a >= m * b)
    {
        second += n * b;
    }
    else
    {
        int fullChargeTime = (n / m) * a;
        second += fullChargeTime;
        n -= n / m * m;
        if (n * b < a)
            second += n * b;
        else
            second += a;
    }

    printf("%d", second);
}