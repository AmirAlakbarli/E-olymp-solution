#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double sum = 0;
    int i = 0;
    for (i = n; i > 0; i--)
    {
        sum += 1.0 / i;
        if (sum > 0.5)
            break;
    }

    printf("%d", i);
}