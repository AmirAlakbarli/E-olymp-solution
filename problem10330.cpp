#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int p[n], ans = n - 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    while (ans && p[ans--] > p[ans])
        ;
    if (ans || p[ans] > p[ans + 1])
        ans++;
    printf("%d", ans);
    return 0;
}