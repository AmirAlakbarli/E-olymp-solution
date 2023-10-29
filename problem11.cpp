#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    printf("%d.", n / m);
    n = n % m * 10;
    int c = 1;
    printf("%d", n / m);

    while (c < k)
    {

        n = n % m * 10;
        c++;
        printf("%d", n / m);
    }
}