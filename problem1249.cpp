#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double p;
    while (scanf("%d", &n) != EOF)
    {
        p = n * log10(n);
        printf("%d\n", (int)pow(10, p - (int)p));
    }
}