#include <bits/stdc++.h>
#define MAX 51

using namespace std;

int arr[MAX][MAX], used[MAX];
int n, flag = 0;

void dfs(int v)
{
    if (flag)
        return;

    used[v] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (arr[v][i])
        {
            if (used[i] == 0)
                dfs(i);
            else if (used[i] == 1)
                flag = 1;
        }
    }
    used[v] = 2;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(used, 0, sizeof(used));

    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    cout << flag;
}