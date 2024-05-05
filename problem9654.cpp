#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int g[MAX][MAX], d[MAX], f[MAX], visited[MAX], t = 1, n;

void dfs(int v)
{
    visited[v] = 1;
    d[v] = t++;

    for (int i = 1; i <= n; i++)
    {
        if (g[v][i] && !visited[i])
        {
            dfs(i);
        }
    }
    f[v] = t++;
}

void dfs1(int v)
{
    visited[v] = 1;
    cout << "Vertex: " << v << ", Gray " << d[v] << ", Black " << f[v] << endl;
    for (int i = 1; i <= n; i++)
    {
        if (g[v][i] && !visited[i])
        {
            dfs1(i);
        }
    }
}

int main()
{
    int v1, v2;
    cin >> n;

    memset(g, 0, sizeof(g));
    memset(visited, 0, sizeof(visited));

    while (cin >> v1 >> v2)
    {
        g[v1][v2] = g[v2][v1] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
}