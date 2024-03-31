#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> findPrimes(int n)
{
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

void segmentedSieve(int l, int r)
{
    if (l < 2)
        l = 2;

    int limit = floor(sqrt(r)) + 1;

    vector<int> primes = findPrimes(limit - 1);

    int low = l;
    int high = l + limit;

    r++;
    vector<bool> mark(limit);
    while (low < r)
    {
        if (high > r)
            high = r;

        mark.clear();
        mark.resize(high - low);
        fill(mark.begin(), mark.end(), true);

        for (int p : primes)
        {
            int loLim = floor(low / p) * p;
            if (loLim < low)
                loLim += p;

            if (loLim == p)
                loLim *= p;

            for (int i = loLim; i < high; i += p)
            {
                mark[i - low] = false;
            }
        }

        for (int i = low; i < high; i++)
        {
            if (mark[i - low])
                cout << i << ' ';
        }

        low += limit;
        high += limit;
    }
}

int main()
{
    int l, r;
    cin >> l >> r;
    segmentedSieve(l, r);
}