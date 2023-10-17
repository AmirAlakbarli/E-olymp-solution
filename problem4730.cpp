#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a0 = 0, a1 = 1;

    for (int i = 0; i < n; i++)
    {
        int a2 = a0 + a1;
        a0 = a1;
        a1 = a2;
    }

    printf("%d", a1);
}