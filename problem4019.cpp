#include <stdio.h>

int main()
{
    short n, m;
    int num;
    scanf("%hd%hd", &n, &m);
    short path[n + 1][m + 1][2];
    path[1][1][0] = -1;
    path[1][1][1] = -1;

    int colSum[m + 1], rowSum;

    for (short i = 1; i <= m; i++)
        colSum[i] = 0;

    for (short i = 1; i <= n; i++)
    {
        rowSum = 0;
        for (short j = 1; j <= m; j++)
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

    printf("%d\n", colSum[m]);

    short shortPath[n + m - 1][2];
    short i = n, j = m, k = 0;
    while (i != 1 || j != 1)
    {
        shortPath[k][0] = i;
        shortPath[k][1] = j;
        k++;
        short tempI = path[i][j][0];
        short tempJ = path[i][j][1];
        i = tempI;
        j = tempJ;
    }

    shortPath[k][0] = 1;
    shortPath[k][1] = 1;

    for (short i = k; i >= 0; i--)
    {
        printf("%hd %hd", shortPath[i][0], shortPath[i][1]);
        if (i != 0)
            printf("\n");
    }
}