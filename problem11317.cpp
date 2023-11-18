#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<double> v(n);
    double var = 0, mean = 0;
    int r;
    for (r = 0; r < k; r++)
    {
        cin >> v[r];
        mean += v[r] / k;
    }

    for (int i = 0; i < k; i++)
    {
        var += (v[i] - mean) / (k - 1) * (v[i] - mean);
    }

    int l = 0;
    var = sqrt(var);
    cout << var << '\n';

    while (r < n)
    {
        cin >> v[r];
        double tmean = mean;
        mean = mean + v[r] / k - v[l] / k;
        var = var * var + v[r] / (k - 1) * v[r] - v[l] / (k - 1) * v[l] + (v[l] - v[r]) / (k - 1) * (mean + tmean);
        var = sqrt(var);
        cout << var << '\n';
        l++;
        r++;
    }

    return 0;
}
