#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int matrix[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
        matrix[i][0] = 0;
    for (int i = 0; i < m + 1; i++)
        matrix[0][i] = 0;

    int num;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            scanf("%d", &num);
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + num;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}