#include <stdio.h>

typedef long long ll;

ll min(ll a, ll b)
{
    return a < b ? a : b;
}

ll sq(ll a)
{
    return a * a;
}

int main()
{
    int n, num1, num2, num3, tempNum;
    scanf("%d", &n);

    ll sum1 = 0, sum2 = 0, tempSum = 0;

    scanf("%d%d", &num2, &num3);
    sum2 = sq(num3 - num2);

    if (n > 2)
    {
        num1 = num2;
        num2 = num3;
        scanf("%d", &num3);
        sum2 = min(sum2, sum1 + 3 * sq(num3 - num1) + sq(num3 - num2));
    }

    if (n > 3)
    {
        for (int i = 3; i < n; i++)
        {
            tempNum = num3;
            tempSum = sum2;
            scanf("%d", &num3);
            sum2 = min(sum1 + 3 * sq(tempNum - num1), min(sum2 + sq(tempNum - num2), sum2 + 3 * sq(num3 - num2) + sq(num3 - tempNum)));
            sum1 = tempSum;
            num1 = num2;
            num2 = tempNum;
        }
    }

    if (n > 2)
        sum2 = min(sum2 + sq(num3 - num2), sum1 + 3 * sq(num3 - num1));

    printf("%lld", sum2);
}