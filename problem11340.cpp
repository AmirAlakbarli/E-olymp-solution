#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[n];

    for (auto &i : arr)
        cin >> i;

    int l = 0, r = 0, res = 0;
    set<int> s;
    for (r = 0; r < n; r++)
    {
        while (l <= r && s.count(arr[r]))
        {
            s.erase(arr[l]);
            l++;
        }
        s.insert(arr[r]);
        res = max(res, r - l + 1);
    }

    cout << res;
}