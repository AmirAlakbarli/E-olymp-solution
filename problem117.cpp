#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> nums(n);

    for (int &i : nums)
    {
        cin >> i;
        sum += i;
    }

    int l = 0, r = sum / m, best = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int cnt = 0;

        for (int ni : nums)
            cnt += ni / mid;

        if (cnt >= m)
        {
            best = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << best;
}