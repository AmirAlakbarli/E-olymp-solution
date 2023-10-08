#include <stdio.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if ((m + n - 2) % 3 != 0)
        printf("0");
    else
    {
        int sum = (m + n - 2) / 3;
        int a = (2 * m - n - 1) / 3;
        if (2 * a > sum)
            a = sum - a;

        unsigned long long res = 1;
        for (int i = a + 1; i <= sum; i++)
        {
            res = res * i / (i - a);
        }

        printf("%llu", res);
    }
}