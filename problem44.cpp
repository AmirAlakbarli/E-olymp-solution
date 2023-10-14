#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n + 1];
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int min = a[i - 1] + 1;
        for (int j = i / 2; j > 1; j--)
        {
            if (i % j == 0 && a[j] + a[i / j] < min)
                min = a[j] + a[i / j];
        }
        a[i] = min;
    }
    printf("%d", a[n]);
}