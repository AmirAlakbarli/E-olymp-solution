#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    int count = 0;
    while (a >= 0)
    {
        a /= 10;
        count++;
        if (a == 0)
            break;
    }
    printf("%d", count);
}