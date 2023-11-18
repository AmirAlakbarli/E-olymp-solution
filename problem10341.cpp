#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int min = 2, max = (c - b) >= (b - a) ? (c - b) : (b - a);
    max--;
    if (b - a == 1 && c - b == 1)
    {
        min = 0;
        max = 0;
    }

    if (b - a == 2 || c - b == 2)
    {
        min = 1;
    }
    printf("%d\n%d", min, max);
}