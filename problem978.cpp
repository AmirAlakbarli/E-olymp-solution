#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int n, g[MAX][MAX], visited[MAX];

void dfs(int v)
{
    visited[v] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (g[v][i] && !visited[i])
        {
            cout << v << " " << i << endl;
            dfs(i);
        }
    }
}

int main()
{
    int m, v1, v2;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        g[v1][v2] = g[v2][v1] = 1;
    }
    dfs(1);
}