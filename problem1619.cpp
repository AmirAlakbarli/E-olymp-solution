#include <stdio.h>
#include <vector>

using namespace std;

typedef unsigned long long llu;

int main()
{
    int n;
    scanf("%d", &n);

    llu mon1, mon2;
    if (n == 1)
    {
        scanf("%llu", &mon1);
        printf("%llu", mon1);
    }
    else
    {
        scanf("%llu %llu", &mon1, &mon2);
        llu maxMoney1 = mon1;
        llu maxMoney2 = mon1 > mon2 ? mon1 : mon2;

        for (int i = 2; i < n; i++)
        {
            llu mon;
            scanf("%llu", &mon);
            llu temp = maxMoney2;
            maxMoney2 = mon + maxMoney1 > maxMoney2 ? mon + maxMoney1 : maxMoney2;
            maxMoney1 = temp;
        }

        printf("%llu", maxMoney2);
    }
}