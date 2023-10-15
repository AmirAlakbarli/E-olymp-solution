#include <stdio.h>

typedef unsigned long long llu;

int main()
{
    int n, m, num;
    scanf("%d%d", &n, &m);
    int path[n + 1][m + 1][2];
    path[1][1][0] = -1;
    path[1][1][1] = -1;

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
                {
                    path[i][j][0] = i;
                    path[i][j][1] = j - 1;
                    colSum[j] = colSum[j - 1] + num;
                }
                else
                {
                    path[i][j][0] = i - 1;
                    path[i][j][1] = j;
                    colSum[j] = colSum[j] + num;
                }
            }
            else if (i == 1 && j > 1)
            {
                colSum[j] = colSum[j - 1] + num;
                path[i][j][0] = i;
                path[i][j][1] = j - 1;
            }
            else if (i > 1 && j == 1)
            {
                colSum[j] += num;
                path[i][j][0] = i - 1;
                path[i][j][1] = j;
            }
            else
            {
                colSum[j] += num;
            }
            rowSum += num;
        }
    }

    printf("%llu\n", colSum[m]);

    int shortPath[n + m - 1][2];
    int i = n, j = m, k = 0;
    while (i != 1 || j != 1)
    {
        shortPath[k][0] = i;
        shortPath[k][1] = j;
        k++;
        int tempI = path[i][j][0];
        int tempJ = path[i][j][1];
        i = tempI;
        j = tempJ;
    }

    shortPath[k][0] = 1;
    shortPath[k][1] = 1;

    for (int i = k; i >= 0; i--)
    {
        printf("%d %d", shortPath[i][0], shortPath[i][1]);
        if (i != 0)
            printf("\n");
    }
}