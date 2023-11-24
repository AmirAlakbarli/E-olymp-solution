#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> stor(n - 1), diff(n), pref(n);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &stor[i]);

    for (int i = 1; i < n - 1; i++)
    {
        diff[i + 1] = stor[i] - stor[i - 1];
        pref[i + 1] = diff[i + 1] + pref[i - 1];
    }

    int even[n], odd[n];
    // assume 1 is at even index
    int mn = 0;
    for (int i = 0; i <= n - 1; i += 2)
        mn = min(mn, pref[i]);

    even[0] = 1 - mn;
    even[1] = stor[0] - even[0];
    for (int i = 2; i < n; i++)
        even[i] = even[i - 2] + diff[i];

    // assume 1 is at odd index
    mn = 0;
    for (int i = 1; i <= n - 1; i += 2)
        mn = min(mn, pref[i]);

    odd[1] = 1 - mn;
    odd[0] = stor[0] - odd[1];
    for (int i = 2; i < n; i++)
        odd[i] = odd[i - 2] + diff[i];

    set<int> copy;
    for (int &i : even)
    {
        copy.insert(i);
    }

    if (copy.size() == n)
    {
        for (int &i : even)
            printf("%d ", i);
    }
    else
    {
        for (int &i : odd)
            printf("%d ", i);
    }
}