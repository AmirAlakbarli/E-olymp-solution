#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &i : arr)
        cin >> i;

    for (int &i : arr)
    {
        int r = upper_bound(arr.begin(), arr.end(), 2 * i) - arr.begin();
        int l = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
        cout << r - l << " ";
    }
}