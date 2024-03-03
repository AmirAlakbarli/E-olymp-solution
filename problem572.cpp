#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i)
            continue;
        int cnt = 0;
        while (n % i == 0)
            n /= i, cnt++;

        if (cnt > 1)
            printf("%d^%d", i, cnt);
        else
            printf("%d", i);

        if (n > 1)
            printf("*");
    }

    if (n > 1)
        printf("%d", n);
}