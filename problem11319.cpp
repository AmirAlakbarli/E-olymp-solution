#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long r = b;
        b = a % b;
        a = r;
    }

    return a;
}

int main()
{
    long long n, m;
    while (cin >> n && cin >> m)
    {
        long long den = n / gcd(n, m) * m * 2;
        cout << "1/" << den << endl;
    }
}
