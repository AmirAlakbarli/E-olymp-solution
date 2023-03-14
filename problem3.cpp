#include <stdio.h>
#include <math.h>

int main()
{
    int n, k = 1, i = 0, sum;
    scanf("%d", &n);
    for (; k < n; ++i)
        k = pow(i + 1, 3);
    if (!i)
        i++;

    if ((i - 1) * (i - 1) * (i - 1) < n && n <= (i - 1) * (i - 1) * i)
    {
        sum = 3 * (i - 1) * pow(i, 2);
        n = n - pow(i - 1, 3);
    }
    else if ((i - 1) * (i - 1) * i < n && n <= (i - 1) * i * i)
    {
        sum = 3 * pow(i - 1, 3) + 9 * pow(i - 1, 2) + 7 * (i - 1) + 1;
        n = n - pow(i - 1, 2) * i;
    }
    else if ((i - 1) * i * i < n && n <= i * i * i)
    {
        sum = 3 * (pow(i, 3) + pow(i, 2)) - i - 1;
        n = n - pow(i, 2) * (i - 1);
    }
    else
    {
        printf("0");
        return 0;
    }
    for (int i1 = 1; n; i1 += 2)
    {
        for (int i2 = 0; i2 < i1 && n; i2++, n--)
        {
            if (i1 == 1)
                sum += 8;
            else if (i2 == 0 || i2 == i1 / 2)
                sum += 5;
            else
                sum += 3;
        }
    }
    printf("%d", sum);
    return 0;
}