#include <bits/stdc++.h>
using namespace std;
#define ll long long

int isPrime(ll n)
{
    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))
        return 0;
    for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
        if (n % i == 0)
            return 0;
    return 1;
}

vector<ll> findPrimes(ll n)
{
    vector<ll> res;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        res.push_back(n);

    return res;
}

vector<bool> segmentedSieve(ll l, ll r)
{
    vector<bool> res(r - l + 1, true);
    vector<ll> primes = findPrimes(sqrt(r));

    for (ll p : primes)
    {
        ll base = (l / p) * p;
        if (base < l)
            base += p;
        for (ll j = base; j <= r; j += p)
            res[j - l] = false;
        if (base == p)
            res[base - l] = true;
    }

    if (l == 1)
        res[0] = false;

    return res;
}

int main()
{
    long long l, r;
    cin >> l >> r;
    vector<bool> res = segmentedSieve(l, r);
    for (int i = 0; i < res.size(); i++)
        if (res[i])
            cout << i + l << endl;
}