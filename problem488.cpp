#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    n -= 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", (n * (2 * i + 1) - 1) * (i % 2) + (int)pow(-1, i % 2) * (n * i + j) + 1);
        }
        putchar('\n');
    }
}