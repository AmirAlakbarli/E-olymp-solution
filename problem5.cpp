#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void generateMultiplicativePartitions(int n, vector<int> &factors, vector<vector<int>> &partitions)
{
    if (n == 1)
    {
        partitions.push_back(factors);
        return;
    }
    int start = factors.empty() ? 2 : factors.back();
    for (int i = start; i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            generateMultiplicativePartitions(n / i, factors, partitions);
            factors.pop_back();
        }
    }
}

int isPrime(int n)
{
    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))
        return 0;

    for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
        if (n % i == 0)
            return 0;

    return 1;
}

int nthPrime(int n)
{
    int i = 2;

    while (n > 0)
    {
        if (isPrime(i))
            n--;

        i++;
    }
    i--;
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n, num1, num2;
    cin >> n;
    num1 = 2 * n;
    num2 = 2 * n - 1;

    vector<vector<int>> partitionsOfNum1, partitionsOfNum2;
    vector<int> factorsOfNum1, factorsOfNum2;
    generateMultiplicativePartitions(num1, factorsOfNum1, partitionsOfNum1);
    generateMultiplicativePartitions(num2, factorsOfNum2, partitionsOfNum2);

    // Back Sort all the vectors in partitionsOfNum1
    for (auto &p : partitionsOfNum1)
    {
        sort(p.rbegin(), p.rend());
    }

    // Back Sort all the vectors in partitionsOfNum2
    for (auto &p : partitionsOfNum2)
    {
        sort(p.rbegin(), p.rend());
    }

    // Sort the vecotrs in partitionsOfNum1 by lexicographical order
    sort(partitionsOfNum1.begin(), partitionsOfNum1.end());

    // Sort the vecotrs in partitionsOfNum2 by lexicographical order
    sort(partitionsOfNum2.begin(), partitionsOfNum2.end());

    // subtract 1 from each element in the partitionsOfNum1 vector
    for (auto &p : partitionsOfNum1)
    {
        for (int i = 0; i < p.size(); i++)
        {
            p[i] -= 1;
        }
    }

    // subtract 1 from each element in the partitionsOfNum2 vector
    for (auto &p : partitionsOfNum2)
    {
        for (int i = 0; i < p.size(); i++)
        {
            p[i] -= 1;
        }
    }

    unsigned long long result = 1;
    for (int i = 0; i < partitionsOfNum1[0].size(); i++)
    {
        result *= pow(nthPrime(i + 1), partitionsOfNum1[0][i]);
    }

    for (auto p : partitionsOfNum1)
    {
        unsigned long long product = 1;

        for (int i = 0; i < p.size(); i++)
        {
            for (int j = 0; j < p[i]; j++)
            {
                product *= nthPrime(i + 1);

                if (product >= result)
                {
                    break;
                }
            }

            if (product > result)
            {
                break;
            }
        }

        if (product < result)
        {
            result = product;
        }
    }

    for (auto p : partitionsOfNum2)
    {
        unsigned long long product = 1;

        for (int i = 0; i < p.size(); i++)
        {
            for (int j = 0; j < p[i]; j++)
            {
                product *= nthPrime(i + 1);

                if (product > result)
                {
                    break;
                }
            }

            if (product > result)
            {
                break;
            }
        }

        if (product < result)
        {
            result = product;
        }
    }

    cout << result << endl;

    return 0;
}
