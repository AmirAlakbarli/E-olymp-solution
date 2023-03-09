#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

// The fastest algorithm to find nth prime number
int nthPrime(int n)
{
    int count = 0;
    int i = 2;
    while (count < n)
    {
        bool isPrime = true;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            count++;
        }
        i++;
    }
    return i - 1;
}

int main()
{
    int n, num1, num2;
    cin >> n;
    num1 = 2 * n;
    num2 = 2 * n - 1;

    vector<vector<int>> partitions_of_num1, partitions_of_num2;
    vector<int> factor_sof_num1, factors_of_num2;
    generateMultiplicativePartitions(num1, factor_sof_num1, partitions_of_num1);
    generateMultiplicativePartitions(num2, factors_of_num2, partitions_of_num2);

    // Back Sort all the vectors in partitions_of_num1
    for (auto &p : partitions_of_num1)
    {
        sort(p.rbegin(), p.rend());
    }

    // Back Sort all the vectors in partitions_of_num2
    for (auto &p : partitions_of_num2)
    {
        sort(p.rbegin(), p.rend());
    }

    // Sort the vecotrs in partitions_of_num1 by lexicographical order
    sort(partitions_of_num1.begin(), partitions_of_num1.end());

    // Sort the vecotrs in partitions_of_num2 by lexicographical order
    sort(partitions_of_num2.begin(), partitions_of_num2.end());

    // subtract 1 from each element in the partitions_of_num1 vector
    for (auto &p : partitions_of_num1)
    {
        for (int i = 0; i < p.size(); i++)
        {
            p[i] -= 1;
        }
    }

    // subtract 1 from each element in the partitions_of_num2 vector
    for (auto &p : partitions_of_num2)
    {
        for (int i = 0; i < p.size(); i++)
        {
            p[i] -= 1;
        }
    }

    unsigned long long result = 1;
    for (int i = 0; i < partitions_of_num1[0].size(); i++)
    {
        result *= pow(nthPrime(i + 1), partitions_of_num1[0][i]);
    }

    for (auto p : partitions_of_num1)
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

    for (auto p : partitions_of_num2)
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
