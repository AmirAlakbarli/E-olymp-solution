#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int l = 0, r = 0, c = 0, res = 0, resL = 0;
    map<int, int> mp;
    while (l < n)
    {
        while (r < n && c + (mp[v[r]] == 0) <= 2)
        {
            mp[v[r]]++;
            c += (mp[v[r]] == 1);
            r++;
        }

        if (r - l > res)
        {
            resL = l;
            res = r - l;
        }

        c -= (mp[v[l]] == 1);
        mp[v[l]]--;
        l++;
    }

    cout << resL + 1 << " " << res;
}
