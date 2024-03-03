#include <stdio.h>

int isPrime(int n)
{
    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))
        return 0;

    for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 4 || isPrime(n))
        printf("NO");
    else
        printf("YES");
}