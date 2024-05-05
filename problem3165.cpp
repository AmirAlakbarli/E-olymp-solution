#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> used;
int flag = 0;

void dfs(int v, int color)
{
    if (flag)
        return;

    used[v] = color;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (!used[to])
        {
            dfs(to, 3 - color);
        }
        else if (used[to] == color)
        {
            flag = 1;
            return;
        }
    }
}

int main()
{
    int n, m, v1, v2;
    while (cin >> n)
    {
        if (!n)
            break;

        g.clear();
        used.clear();
        g.resize(n + 1);
        used.resize(n + 1, 0);
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> v1 >> v2;
            g[v1].push_back(v2);
            g[v2].push_back(v1);
        }
        dfs(1, 1);

        if (flag)
        {
            cout << "NOT BICOLOURABLE.\n";
        }
        else
        {
            cout << "BICOLOURABLE.\n";
        }
        flag = 0;
    }
}