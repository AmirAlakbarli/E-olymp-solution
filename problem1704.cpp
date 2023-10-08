#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &n, &m);
    n = m + n - 2;
    m = m - 1;
    if (2 * m < n)
        m = n - m;

    unsigned long long res = 1;
    for (int i = m + 1; i <= n; i++)
    {
        res = res * i / (i - m);
    }

    printf("%llu", res);
}