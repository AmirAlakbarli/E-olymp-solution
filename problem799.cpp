#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a, b, c, c1, c2, b1, sum1, sum2, sum3, temp;

    scanf("%d %d %d", &a, &b, &c);
    sum3 = a;
    b1 = b;
    c1 = c;
    if (n >= 2)
    {
        scanf("%d %d %d", &a, &b, &c);
        sum2 = sum3;
        sum3 = sum2 + a > b1 ? b1 : sum2 + a;
        b1 = b;
        c2 = c;
    }
    if (n >= 3)
    {
        scanf("%d %d %d", &a, &b, &c);
        sum1 = sum2;
        sum2 = sum3;
        sum3 = min(sum2 + a, min(sum1 + b1, c1));
        b1 = b;
        c1 = c2;
        c2 = c;
    }
    if (n >= 4)
    {
        for (int i = 3; i < n; i++)
        {
            temp = sum3;

            scanf("%d %d %d", &a, &b, &c);

            sum3 = min(sum3 + a, min(sum2 + b1, sum1 + c1));

            sum1 = sum2;
            sum2 = temp;
            b1 = b;
            c1 = c2;
            c2 = c;
        }
    }
    printf("%d", sum3);
}