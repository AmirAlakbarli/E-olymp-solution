#include <stdio.h>

int main()
{
    int n, m, num, rowSum;
    scanf("%d%d", &n, &m);
    int colSum[m];
    for (int i = 0; i < m; i++)
        colSum[i] = 0;

    for (int i = 0; i < n; i++)
    {
        rowSum = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &num);
            rowSum += num;
            colSum[j] += rowSum;
            printf("%d ", colSum[j]);
        }
        printf("\n");
    }
}