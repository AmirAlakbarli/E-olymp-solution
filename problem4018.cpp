#include <stdio.h>

typedef unsigned long long llu;

int main()
{
    int n, m, num;
    scanf("%d%d", &n, &m);

    llu colSum[m + 1], rowSum;

    for (int i = 1; i <= m; i++)
        colSum[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        rowSum = 0;
        for (int j = 1; j <= m; j++)
        {

            scanf("%d", &num);
            if (i > 1 && j > 1)
            {
                if (colSum[j] > colSum[j - 1])
                    colSum[j] = colSum[j - 1] + num;
                else
                    colSum[j] = colSum[j] + num;
            }
            else if (i == 1 && j > 1)
                colSum[j] = colSum[j - 1] + num;
            else if (i > 1 && j == 1)
                colSum[j] += num;
            else
                colSum[j] += num;

            rowSum += num;
        }
    }

    printf("%llu", colSum[m]);
}