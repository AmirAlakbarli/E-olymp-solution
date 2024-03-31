#include <bits/stdc++.h>

using namespace std;

#define N 105

int g[N][N];
bool vis[N];
int n;

void dfs(int v)
{
    vis[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && g[v][i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int m = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            m += g[i][j];
        }
    }
    m /= 2;

    if (m != n - 1)
    {
        cout << "NO";
        return 0;
    }
    
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES";
}
