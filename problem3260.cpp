#include <stdio.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (2 * k < n)
        k = n - k;
    int res = 1;
    for (int i = k + 1; i <= n; i++)
    {
        res = res * i / (i - k);
    }

    printf("%d", res);
}