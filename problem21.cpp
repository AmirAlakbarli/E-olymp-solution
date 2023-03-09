#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    int p;
    multiset<long long> c;
    cin >> a >> p;
    p = 100 - p;
    int in;
    for (int i = 0; i < a; ++i)
    {
        cin >> in;
        c.insert((in * 100));
    }

    while (a-- > 1)
    {
        auto it_orig = c.begin(), it = it_orig;
        long long s = (long long)round(p * ((*it++) + (*it++)) / 100.0);
        c.erase(it_orig, it);
        c.insert(s);
    }

    long long r = *c.begin();
    cout << r / 100 << '.' << r % 100;
    return 0;
}