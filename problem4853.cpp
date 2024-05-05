#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> dist, parent;

void bfs(int start, int finish)
{
    bool flag = false;
    dist.resize(n + 1, -1);
    parent.resize(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if (dist[to] == -1)
            {
                q.push(to);
                dist[to] = dist[v] + 1;
                parent[to] = v;
            }

            if (to == finish)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
}

void path(int v)
{
    if (v == -1)
        return;
    path(parent[v]);
    cout << v << ' ';
}

int main()
{
    int a, b, u, v;
    cin >> n >> m >> a >> b;
    g.resize(n + 1);
    while (m--)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(a, b);

    if (parent[b] == -1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dist[b] << '\n';
        path(b);
        cout << '\n';
    }
}