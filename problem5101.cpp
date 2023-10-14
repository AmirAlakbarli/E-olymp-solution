#include <stdio.h>

const int MOD = 9929;

int power(int a, int b)
{
    int result = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int binomialCoefficientMod(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }

    int ans = 1;
    while (n > 0 || m > 0)
    {
        int nDigit = n % MOD;
        int mDigit = m % MOD;
        n /= MOD;
        m /= MOD;

        int num = 1;
        int den = 1;

        if (nDigit < mDigit)
        {
            return 0;
        }

        for (int i = 1; i <= mDigit; i++)
        {
            num = (num * (nDigit - i + 1)) % MOD;
            den = (den * i) % MOD;
        }

        ans = (ans * num) % MOD;
        ans = (ans * power(den, MOD - 2)) % MOD;
    }

    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    int m = n - 1;
    n = 2 * n - 2;

    int res = binomialCoefficientMod(n, m);
    res *= (n + 1);
    res %= MOD;
    printf("%d", res);
}
