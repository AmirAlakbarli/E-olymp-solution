#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> visited, path;
int flag = 0;

void dfs(int v)
{
    if (flag)
        return;

    visited[v] = 1;
    path.push_back(v);
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!flag && visited[to] == 1)
        {
            path.push_back(to);
            flag = 1;
            return;
        }
        else
            dfs(to);
    }

    if (flag)
        return;

    visited[v] = 2;
    path.pop_back();
}

int main()
{
    int n, m, v1, v2;
    cin >> n >> m;
    g.resize(n + 1), visited.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            if (flag)
                break;
        }
    }

    if (flag)
    {
        int to = path.back();
        int i = path.size() - 2;
        while (path[i] != to)
            i--;

        cout << "YES\n";

        for (; i < path.size() - 1; i++)
        {
            cout << path[i] << " ";
        }

        cout << endl;
    }

    else
        cout << "NO\n";
}