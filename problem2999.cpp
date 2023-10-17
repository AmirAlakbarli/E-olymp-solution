#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if (2 * m < n)
        m = n - m;
    int res = 1;
    for (int i = m + 1; i <= n; i++)
    {
        res = res * i / (i - m);
    }

    printf("%d", res);
}