#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << (n + 1) / 2 << " " << n / 2 << "\n";
    if (n % 2)
    {
        for (int i = 1, t = 1; i <= n; i += t, t = 4 - t)
        {
            cout << i << " ";
        }

        cout << "\n";

        for (int i = 3, t = 1; i <= n; i += t, t = 4 - t)
        {
            cout << i << " ";
        }
    }
    else
    {
        for (int i = 1, t = 3; i <= n; i += t, t = 4 - t)
        {
            cout << i << " ";
        }
        cout << "\n";

        for (int i = 2, t = 1; i <= n; i += t, t = 4 - t)
        {
            cout << i << " ";
        }
    }
}