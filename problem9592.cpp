#include <stdio.h>
#define MOD_NUM 1000000007

typedef unsigned long long llu;

int main()
{
    int n;
    short k;

    scanf("%d %hd", &n, &k);
    llu res = 1;

    int lastProduct = n % 2 ? n - 1 : k * n / 2 + n / 2 - 1;
    int pow = (n + 1) / 2;

    // convert pow to binary
    int bin[32] = {0};
    int binLen = 0;
    while (pow > 0)
    {
        bin[binLen++] = pow % 2;
        pow /= 2;
    }

    for (int i = binLen - 1; i > 0; --i)
    {
        if (bin[i])
            res = res * k % MOD_NUM;

        res = res * res % MOD_NUM;
    }

    if (bin[0])
        res = res * k % MOD_NUM;

    res = (res * lastProduct) % MOD_NUM;

    printf("%llu", res);
}