#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int k, m;
    cin >> k >> m;
    vector<int> d;
    long long f = 120;
    for (int i = 0; i <= 9; i++)
    {
        d.push_back(i);
    }
    if (k == 2)
    {
        for (int i = 0; i <= 9; i++)
        {
            d.push_back(i);
        }
        f = 3628800;
    }
    int n = d.size();
    long long res = 0;

    for (int i = 0; i < 1 << n; i++)
    {
        if (__builtin_popcount(i) != n / 2)
            continue;
        long long cnt1 = f;
        long long sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += d[j];
            }
            else
            {
                sum -= d[j];
            }
        }
        if ((sum % 11 + 11) % 11 != m)
            continue;
        long long cnt2 = 0;
        int zero = 0;
        for (int j = 0; j < n; j++)
        {
            if (!(i & (1 << j)))
            {
                if (d[j] != 0)
                {
                    cnt1 *= ++cnt2;
                }
                else
                {
                    zero++;
                }
            }
        }
        if (zero == 1)
        {
            cnt1 = cnt1 * (n / 2 - 1);
        }
        if (zero == 2)
        {
            cnt1 = cnt1 * (n / 2 - 1);
            cnt1 = cnt1 * (n / 2 - 2);
        }
        for (int j = 0; j <= 9; j++)
        {
            if (k == 2)
                cnt1 /= 2;
        }
        res += cnt1;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}