#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    while (n--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < b; k++)
                {
                    cout << s[j];
                }
            }
            cout << '\n';
        }
    }
}
