#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int res = 1;
    for (int i = 2; i * i <= n; i++)
    {
        int cnt = 0;
        while (n % i == 0)
            n /= i, cnt++;

        res *= (2 * cnt + 1);
    }

    if (n > 1)
        res *= 3;

    printf("%d", res);
}