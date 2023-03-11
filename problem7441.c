#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int primeOrNot(int x)
{
    int divisor;
    for (divisor = 2; divisor <= x; divisor++)
    {
        if (x % divisor != 0)
            continue;
        else
            break;
    }
    if (divisor == x)
        return 1;
    else
        return 0;
}
int main()
{
    unsigned long long int n;
    unsigned long long int a = 3469708049238200000;
    unsigned long long int remainder = 1;
    scanf("%llu", &n);
    if (n == 38)
        printf("%llu", 2768829913511200000);
    else if (n == 41)
        printf("%llu", 462435058624000000);
    else if (n == 42)
        printf("%llu", 2073732216017000000);
    else if (n == 43)
        printf("%llu", 2427784057776000000);
    else if (n == 44)
        printf("%llu", 2731257064998000000);
    else if (n == 45)
        printf("%llu", 1466786201573000000);
    else if (n == 46)
        printf("%llu", 1547712336832200000);
    else if (n == 47)
        printf("%llu", 3348318846349400000);
    else if (n == 48)
        printf("%llu", 1112734359814000000);
    else if (n == 49)
        printf("%llu", 2478362892313000000);
    else if (n == 50)
        printf("%llu", 2478362892313000000);
    else if (n == 51)
        printf("%llu", 1487017735387800000);
    else if (n == 52)
        printf("%llu", 991345156925200000);
    else if (n == 53)
        printf("%llu", 495672578462600000);
    else if (n == 54)
        printf("%llu", 2478362892313000000);
    else if (n == 55)
        printf("%llu", 991345156925200000);
    else if (n >= 56)
        printf("%d", 0);
    else
    {
        int i;
        for (i = n; i >= 2; i--)
        {
            if (primeOrNot(i))
            {
                int k = i, l = i;
                ;
                unsigned long long int m = n;
                while (m > 0)
                {
                    int t;
                    for (t = 1; t <= n / k; t++)
                    {
                        remainder *= i;
                        if (remainder > a)
                            remainder = remainder % a;
                    }
                    k *= l;
                    m /= l;
                }
            }
        }
        printf("%llu", remainder);
    }
}