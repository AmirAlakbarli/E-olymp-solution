#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, num, p = 0;
    cin >> n;
    int l = -3, r = -2;
    map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        p += num;
        p %= n;
        if (p < 0)
            p += n;
        if (mp.count(p))
        {
            l = mp[p];
            r = i;
            break;
        }
        mp[p] = i;
    }
    cout << l + 2 << " " << r + 1;

    return 0;
}